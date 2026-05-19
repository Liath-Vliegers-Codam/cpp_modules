#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <ctime>
#include <limits>
#include <iomanip>


#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

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


};

// std::ostream& operator<<(std::ostream &output_stream, BitcoinExchange& src);

// // Exceptions
// class ExceptionName : public std::exception
// {
// 	const char* what() const noexcept override;
// };

bool check_date(std::string date, std::string file);
bool is_int(std::string input);
bool is_double(std::string input);

void print_map(std::map<std::string, double> data);		// TAKE OUT
