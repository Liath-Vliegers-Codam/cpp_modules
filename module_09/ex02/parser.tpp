#include "parser.hpp"

template <typename Container>
void print_container(const Container &cont, const std::string &prefix)
{
	std::cout << prefix;
	for (typename Container::const_iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


static bool check_token(std::string token)
{
	for (size_t i = 0; i < token.length(); i++)
	{
		if (!isdigit(token[i]))
			return (false);
	}
	return (true);
}


// Container::value_type must be convertible from int
template <typename Container>
Container parse_part(std::string input)
{
	Container parsed_input;
	std::stringstream sstream(input);
	std::string token;

	while (sstream >> token)
	{
		// std::cout << YELLOW << "token = " << token << DEFAULT << std::endl;
		if (!check_token(token))
		{
			throw std::runtime_error("Error (check_token() failed (invalid token))");
		}

		int value;
		try
		{
			value = stoi(token);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("Error (stoi() failed (probably overflow))");
		}
		parsed_input.push_back(static_cast<typename Container::value_type>(value));
	}
	return (parsed_input);
}

template <typename Container>
Container parse_input(char* argv[])
{
	Container parsed_input;

	try
	{
		for (int i = 0; argv[i] != NULL; i++)
		{
			// std::cout << GREEN << "input #" << i << " = " << argv[i] << DEFAULT << std::endl;
			Container part = parse_part<Container>(argv[i]);
    		parsed_input.insert(parsed_input.end(), part.begin(), part.end());
		}
	}
	catch(const std::exception& e)
	{
		throw std::runtime_error(e.what());
	}
	return (parsed_input);
}
