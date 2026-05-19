#include "BitcoinExchange.hpp"


// ===============================================================================================================

// Constructors
BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream data_file("./data.csv");
	if (!data_file.is_open())
	{
		throw std::runtime_error("The [data.csv] file is required for this program, but it is missing or unable to open in this repository");
		return ;
	}

	std::string line;
	bool error = false;

	std::getline(data_file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << RED << "Error : wrong format of the header. Should be [date,exchange_rate]" << std::endl;
		error = true;
	}

	int line_nbr = 1;
	while (std::getline(data_file, line))
	{
		line_nbr++;

		size_t split_pos = line.find(',');
		if (split_pos == std::string::npos)
		{
			std::cerr << RED << "Error : wrong format of the delimiter in data.csv at line [" << line_nbr << "] : " << line << DEFAULT << std::endl;
			error = true;
			continue;
		}
		
		std::string date = line.substr(0, split_pos);
		std::string exchange_rate_str = line.substr(split_pos + 1);

		if (!check_date(date, "data_file"))
		{
			std::cerr << RED << "Error : wrong format of the date in data.csv at line [" << line_nbr << "] : " << line << DEFAULT << std::endl;
			error = true;
			continue;
		}
		if (!is_int(exchange_rate_str) && !is_double(exchange_rate_str))
		{
			std::cerr << RED << "Error : wrong format of the exchange_rate in data.csv at line [" << line_nbr << "] : " << line << DEFAULT << std::endl;
			error = true;
			continue;
		}

		double exchange_rate;
		try
		{
			exchange_rate = stof(exchange_rate_str);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error : wrong format of the exchange_rate in data.csv at line [" << line_nbr << "] : " << line << DEFAULT << std::endl;
			error = true;
			continue;
		}
		
		this->_data.insert({date, exchange_rate});
	}

	data_file.close();

	if (error)
	{
		throw std::runtime_error("Please fix these mistakes to run this program");
		return ;
	}

	print_map(this->_data);		// TAKE OUT

}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
	std::cout << BLUE << "BitcoinExchange copy constructor is called" << DEFAULT<< std::endl;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << BLUE << "BitcoinExchange destructor is called" << DEFAULT<< std::endl;
}

// Getters and Setters

// Member functions

// Overload operators
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_data = other._data;
		std::cout << BLUE << "BitcoinExchange copy assignment is called" << DEFAULT<< std::endl;
	}
	return (*this);
}

// std::ostream& operator<<(std::ostream& output_stream, BitcoinExchange& src)
// {
// 	output_stream << "*BitcoinExchange Class info here*" << std::endl;
// 	return (output_stream);
// }

// // Exceptions
// const char* ExceptionName::what() const noexcept
// {
// 	return ("*Exception info here*");
// }



