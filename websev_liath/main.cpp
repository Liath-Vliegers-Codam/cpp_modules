// Standard C++ headers used for output, strings, and containers.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cctype>

// System headers used for sockets, non-blocking mode, and polling.
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Simple ANSI colors for clearer terminal output.
static const char* C_RESET  = "\033[0m";
static const char* C_INFO   = "\033[36m";
static const char* C_OK     = "\033[32m";
static const char* C_WARN   = "\033[33m";
static const char* C_ERR    = "\033[31m";

// This structure stores everything we need for one connected client.
// - in: data received from the client but not yet fully processed
// - out: response data prepared for the client
// - sent: how many bytes from 'out' were already written
// - readyToWrite: whether we have a response ready and should switch to POLLOUT
struct ClientState 
{
    std::string in;
    std::string out;
    size_t sent;
    bool readyToWrite;
    ClientState() : sent(0), readyToWrite(false) {}
};

// Put a file descriptor into non-blocking mode.
// This is required so accept/recv/send do not block the whole server.
static bool setNonBlocking(int fd) 
{
    // Read the current flags first so we can add O_NONBLOCK without removing anything.
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) 
		return false;
    // Write the flags back with O_NONBLOCK enabled.
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) < 0) 
		return false;
    return true;
}

// Create, configure, bind, and listen on one TCP socket.
// For this demo, it listens on the given port on all interfaces.
static int createListenSocket(int port) 
{
    // Create a TCP socket using IPv4.
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) 
		return -1;

    // Allow quick restart of the server without waiting for the port to fully release.
    int yes = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    // Make the listening socket non-blocking before entering the event loop.
    if (!setNonBlocking(fd)) 
	{ 
		close(fd); 
		return -1; 
	}

    // Prepare the address structure for bind().
    sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    // Bind the socket to the chosen port.
    if (bind(fd, (sockaddr*)&addr, sizeof(addr)) < 0) 
	{
		close(fd); 
		return -1; 
	}
    // Start listening for incoming connections.
    if (listen(fd, 128) < 0) 
	{ 
		close(fd); 
		return -1; 
	}

    return fd;
}

    // Remove leading and trailing whitespace from one line.
    static std::string trim(const std::string& s)
    {
        size_t start = 0;
        while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
            ++start;

        size_t end = s.size();
        while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
            --end;

        return s.substr(start, end - start);
    }

    // Check if a string contains only digits.
    static bool isDigits(const std::string& s)
    {
        if (s.empty())
            return false;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (!std::isdigit(static_cast<unsigned char>(s[i])))
                return false;
        }
        return true;
    }

    // Load all listening ports from either:
    // - a numeric command-line argument like "8080"
    // - a small config file containing lines such as: listen 8080;
    // If nothing valid is found, use 8080.
    static std::vector<int> loadListenPorts(int argc, char** argv)
	{
        std::vector<int> ports;

    	if (argc >= 2)
        {
            std::string arg = argv[1];

            // If the argument is only digits, treat it as a direct port number.
            if (isDigits(arg))
            {
                ports.push_back(std::atoi(arg.c_str()));
                return ports;
            }

            // Otherwise, treat it as a config file path.
            std::ifstream file(arg.c_str());
            if (file.is_open())
            {
                std::string line;

                while (std::getline(file, line))
                {
                    line = trim(line);

                    // Skip empty lines and comments.
                    if (line.empty() || line[0] == '#')
                        continue;

                    // Very small NGINX-like syntax:
                    // listen 8080;
                    if (line.compare(0, 6, "listen") == 0)
                    {
                        std::string value = trim(line.substr(6));

                        if (!value.empty() && value[value.size() - 1] == ';')
                            value = trim(value.substr(0, value.size() - 1));

                        if (isDigits(value))
                            ports.push_back(std::atoi(value.c_str()));
                    }
                }

                if (!ports.empty())
                    return ports;
            }
        }

        // Default port if no valid configuration was found.
        ports.push_back(8080);
        return ports;
    }

    // Check whether one file descriptor belongs to the listening sockets.
    static bool isListenSocket(const std::vector<int>& listenSockets, int fd)
    {
        for (size_t i = 0; i < listenSockets.size(); ++i)
        {
            if (listenSockets[i] == fd)
                return true;
        }
        return false;
}

// Extract the request target from the first line of an HTTP request.
// Example: "GET /missing HTTP/1.1" -> "/missing"
static std::string getRequestPath(const std::string& request)
{
    size_t lineEnd = request.find("\r\n");
    if (lineEnd == std::string::npos)
        lineEnd = request.size();

    std::string firstLine = request.substr(0, lineEnd);
    size_t firstSpace = firstLine.find(' ');
    if (firstSpace == std::string::npos)
        return "/";

    size_t secondSpace = firstLine.find(' ', firstSpace + 1);
    if (secondSpace == std::string::npos)
        return "/";

    return firstLine.substr(firstSpace + 1, secondSpace - firstSpace - 1);
}

// Extract the HTTP method from the first request line.
// Example: "GET / HTTP/1.1" -> "GET"
static std::string getRequestMethod(const std::string& request)
{
    size_t lineEnd = request.find("\r\n");
    if (lineEnd == std::string::npos)
        lineEnd = request.size();

    std::string firstLine = request.substr(0, lineEnd);
    size_t firstSpace = firstLine.find(' ');
    if (firstSpace == std::string::npos)
        return "UNKNOWN";

    return firstLine.substr(0, firstSpace);
}

// Extract status code text from response first line.
// Example: "HTTP/1.1 404 Not Found" -> "404 Not Found"
static std::string getStatusFromResponse(const std::string& response)
{
    size_t lineEnd = response.find("\r\n");
    if (lineEnd == std::string::npos)
        return "unknown";

    std::string firstLine = response.substr(0, lineEnd);
    size_t firstSpace = firstLine.find(' ');
    if (firstSpace == std::string::npos || firstSpace + 1 >= firstLine.size())
        return "unknown";

    return firstLine.substr(firstSpace + 1);
}

// Build a plain text HTTP response with an optional extra header line.
static std::string makeTextResponse(const std::string& status,
                                    const std::string& body,
                                    const std::string& extraHeader)
{
    std::string response;
    std::ostringstream contentLength;
    contentLength << body.size();

    response += "HTTP/1.1 " + status + "\r\n";
    response += "Content-Type: text/plain\r\n";
    response += "Content-Length: " + contentLength.str() + "\r\n";
    if (!extraHeader.empty())
        response += extraHeader + "\r\n";
    response += "Connection: close\r\n";
    response += "\r\n";
    response += body;
    return response;
}

// Build the response we want to send back.
// For now:
// - supports GET, POST, DELETE
// - unsupported method => 405 Method Not Allowed
// - unknown path => 404 Not Found
static std::string buildDemoResponse(const std::string& method, const std::string& path)
{
    if (method != "GET" && method != "POST" && method != "DELETE")
        return makeTextResponse("405 Method Not Allowed",
                                "405 Method Not Allowed\n",
                                "Allow: GET, POST, DELETE");

    if (path != "/")
        return makeTextResponse("404 Not Found", "404 Not Found\n", "");

    if (method == "GET")
        return makeTextResponse("200 OK", "hello from webserv!\n", "");

    if (method == "POST")
        return makeTextResponse("201 Created", "POST request accepted\n", "");

    return makeTextResponse("200 OK", "DELETE request accepted\n", "");
}

// Close one client connection and remove all of its bookkeeping data.
static void closeClient(std::vector<pollfd>& fds, std::map<int, ClientState>& clients, size_t i) 
{
    // Get the file descriptor from the poll list entry.
    int fd = fds[i].fd;
    // Close the kernel-side socket.
    close(fd);
    // Remove the client state from the map.
    clients.erase(fd);
    // Remove the poll entry so this descriptor is no longer monitored.
    fds.erase(fds.begin() + i);
}

int main(int argc, char** argv) 
{
    // Load one or more listening ports.
    std::vector<int> listenPorts = loadListenPorts(argc, argv);

    // Keep track of all listening sockets so we can recognize them later.
    std::vector<int> listenSockets;

    // 'fds' contains every file descriptor watched by poll().
    std::vector<pollfd> fds;
    // 'clients' stores per-client buffers and state.
    std::map<int, ClientState> clients;

    // Create one listening socket per configured port.
    for (size_t i = 0; i < listenPorts.size(); ++i)
    {
        int listenFd = createListenSocket(listenPorts[i]);
        if (listenFd < 0)
		{
            std::cerr << C_ERR << "[ERR] " << C_RESET
                      << "Failed to create listen socket on port " << listenPorts[i] << "\n";

            // Close any sockets that were already opened.
            for (size_t j = 0; j < listenSockets.size(); ++j)
                close(listenSockets[j]);
            return 1;
        }

        listenSockets.push_back(listenFd);

        // Add this listening socket to the poll list.
        pollfd p;
        p.fd = listenFd;
        p.events = POLLIN;
        p.revents = 0;
        fds.push_back(p);
    }

    // Show all listening ports.
    for (size_t i = 0; i < listenPorts.size(); ++i)
        std::cout << C_OK << "[OK]  " << C_RESET
                  << "Listening on :" << listenPorts[i] << "\n";

    // Main event loop: wait for sockets to become readable/writable.
    while (true) 
	{
        // poll() sleeps until something happens or the timeout expires.
        int n = poll(&fds[0], fds.size(), 5000);
        if (n < 0) 
		{
            std::cerr << C_ERR << "[ERR] " << C_RESET << "poll failed\n";
            break;
        }
        // Nothing happened during this interval, so start the next loop iteration.
        if (n == 0) continue;

        // Step 1: if any listening socket is ready, accept all queued clients.
        for (size_t i = 0; i < fds.size(); ++i)
		{
            if (!isListenSocket(listenSockets, fds[i].fd))
                continue;

            if (!(fds[i].revents & POLLIN))
                continue;

            // Keep accepting until the accept queue is empty.
            while (true) 
			{
                // accept() returns a new connected client socket.
                int cfd = accept(fds[i].fd, 0, 0);
                // In non-blocking mode, accept() fails when there are no more pending clients.
                if (cfd < 0) break; // non-blocking accept queue drained
                // Put the client socket into non-blocking mode too.
                if (!setNonBlocking(cfd)) 
				{ 
					close(cfd); continue; 
				}

                std::cout << C_INFO << "[INFO]" << C_RESET
                          << " New client fd=" << cfd << "\n";

                // Add this client to the poll list so we can watch it later.
                pollfd cp;
                cp.fd = cfd;
                cp.events = POLLIN;
                cp.revents = 0;
                fds.push_back(cp);
                // Create empty per-client state.
                clients[cfd] = ClientState();
            }
        }

        // Step 2: process every connected client socket.
        for (size_t i = 1; i < fds.size(); ) 
		{
            // Current client file descriptor.
            int fd = fds[i].fd;

            // Skip listening sockets during client processing.
            if (isListenSocket(listenSockets, fd))
            {
                ++i;
                continue;
            }

            // Events reported by poll() for this socket.
            short rev = fds[i].revents;

            // If the socket has an error or hangup, close it immediately.
            if (rev & (POLLERR | POLLHUP | POLLNVAL)) 
			{
                closeClient(fds, clients, i);
                continue;
            }

            // Retrieve the state associated with this client.
            ClientState& c = clients[fd];

            // If the socket is readable and we still need request data, read from it.
            if ((rev & POLLIN) && !c.readyToWrite) 
			{
                // Temporary buffer for incoming bytes.
                char buf[4096];
                // recv() reads whatever is currently available without blocking.
                ssize_t r = recv(fd, buf, sizeof(buf), 0);
                // If the client disconnected or an error happened, close the connection.
                if (r <= 0) // do not read again; close
				{ 
                    closeClient(fds, clients, i);
                    continue;
                }
                // Append the newly received bytes to the client's input buffer.
                c.in.append(buf, r);

                // Once we see \r\n\r\n, the HTTP headers are complete.
                if (c.in.find("\r\n\r\n") != std::string::npos) 
				{
                    // Decide which response to send based on the requested path.
                    std::string method = getRequestMethod(c.in);
                    std::string path = getRequestPath(c.in);
                    c.out = buildDemoResponse(method, path);
                    std::string status = getStatusFromResponse(c.out);

                    const char* levelColor = C_OK;
                    if (status.size() >= 1 && status[0] == '4')
                        levelColor = C_WARN;
                    else if (status.size() >= 1 && status[0] == '5')
                        levelColor = C_ERR;

                    std::cout << levelColor << "[REQ] " << C_RESET
                              << method << " " << path
                              << " -> " << status
                              << " (fd=" << fd << ")\n";
                    // Start sending from the beginning of the response.
                    c.sent = 0;
                    // Mark this client as ready for the write phase.
                    c.readyToWrite = true;
                    // Switch the poll interest from POLLIN to POLLOUT.
                    fds[i].events = POLLOUT; // switch to write readiness
                }
            }

            // If the socket is writable and the response is ready, send data.
            if ((rev & POLLOUT) && c.readyToWrite) 
			{
                // Pointer to the unsent part of the response.
                const char* data = c.out.c_str() + c.sent;
                // Number of bytes still waiting to be sent.
                size_t left = c.out.size() - c.sent;
                // send() may write only part of the response.
                ssize_t w = send(fd, data, left, 0);
                // If the write failed or the peer closed, stop using this socket.
                if (w <= 0) // do not write again; close
				{ 
                    closeClient(fds, clients, i);
                    continue;
                }
                // Record how many bytes were successfully written.
                c.sent += (size_t)w;
                // Once the full response is sent, close the connection.
                if (c.sent >= c.out.size()) 
				{
                    closeClient(fds, clients, i); // Connection: close
                    continue;
                }
            }

            // Move to the next client.
            ++i;
        }
    }

    // Clean up the listening socket on shutdown.
    for (size_t i = 0; i < listenSockets.size(); ++i)
        close(listenSockets[i]);
    return 0;
}