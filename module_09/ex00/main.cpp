
#include "BitcoinExchange.hpp"
#include "utils.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc;
		btc.readInputFile(argv[1]);
	}

	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl;
		return (2);
	}
	return (0);
}
