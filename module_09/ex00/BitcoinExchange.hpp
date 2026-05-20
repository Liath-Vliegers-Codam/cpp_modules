#pragma once

#include "utils.hpp"


class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
	
	public:
		// Constructors
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);

		// Destructor
		~BitcoinExchange(void);

		// Operators
		BitcoinExchange &operator=(const BitcoinExchange& other);

		// Getters and Setters

		// Member functions
		void readInputFile(std::string path);
};
