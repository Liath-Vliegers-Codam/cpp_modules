#include "BitcoinExchange.hpp"
#include "utils.hpp"

static bool check_date(std::string date, std::string file)
{
	int year;
	int month;
	int day;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		return (false);
	}

	try
	{
		year = stoi(date.substr(0, 4));
		month = stoi(date.substr(5, 2));
		day = stoi(date.substr(8, 2));
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
		return (false);
	}

	std::time_t now = std::time(nullptr);
	std::tm *datetime = std::localtime(&now);

	// check for valid year
	if (year < 2009 || year > datetime->tm_year + 1900) // bitcoin launched in 2009 and it can not be the future
	{
		return (false);
	}

	// check for valid month
	if (month < 1 || month > 12)
	{
		return (false);
	}

	// check for valid day
	if (day < 1 || day > 31)
	{
		return (false);
	}

	// check for months with 30 days
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		return (false);
	}

	// check for February
	if (month == 2)
	{
		bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (day > 29 || (day == 29 && !is_leap_year))
		{
			return (false);
		}
	}

	// check if the date coming from data_file is in the future
	if (file == "data_file" && year == datetime->tm_year + 1900)
	{
		if (month > datetime->tm_mon + 1 || (month == datetime->tm_mon + 1 && day > datetime->tm_mday))
		{
			return (false);
		}
	}

	// check if date coming from input_file is in the future or before the first date in data_file
	if (file == "input_file")
	{
		if (year < 2009 || (year == 2009 && month < 1) || (year == 2009 && month == 1 && day < 2))
		{
			return (false);
		}
	}

	return (true);
}

static bool check_exchange_rate(std::string exchange_rate_str, double *exchange_rate, bool *error)
{
	if (!is_int(exchange_rate_str) && !is_double(exchange_rate_str))
	{
		*error = true;
		return false;
	}

	try
	{
		*exchange_rate = stod(exchange_rate_str);
	}
	catch (const std::out_of_range&)
	{
		*error = true;
		return (false);
	}
	catch(const std::exception&)
	{
		*error = true;
		return (false);
	}

	return (true);
}

static bool check_input_value(std::string value_str, double *value, std::string line)
{		
	if (!is_int(value_str) && !is_double(value_str))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}

	try
	{
		*value = std::stod(value_str);
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	catch (const std::out_of_range&)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}

	if (*value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (*value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

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

		double exchange_rate;

		if (!check_exchange_rate(exchange_rate_str, &exchange_rate, &error))
		{
			std::cerr << RED << "Error : wrong format of the exchange_rate in data.csv at line [" << line_nbr << "] : " << line << DEFAULT << std::endl;
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
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
	// std::cout << BLUE << "BitcoinExchange copy constructor is called" << DEFAULT<< std::endl;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
    // std::cout << BLUE << "BitcoinExchange destructor is called" << DEFAULT<< std::endl;
}

// Overload operators
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_data = other._data;
		// std::cout << BLUE << "BitcoinExchange copy assignment is called" << DEFAULT<< std::endl;
	}
	return (*this);
}

// Member functions
void BitcoinExchange::readInputFile(std::string path)
{
	std::ifstream input_file(path);
	if (!input_file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;

	std::getline(input_file, line);
	if (line != "date | value")
	{
		std::cerr << "Error: bad input => " << line << std::endl;
	}

	while (std::getline(input_file, line))
	{
		size_t split_pos = line.find('|');
		if (split_pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim_whitespaces(line.substr(0, split_pos));
		std::string value_str = trim_whitespaces(line.substr(split_pos + 1));

		if (!check_date(date, "input_file"))
		{
    		std::cerr << "Error: bad input => " << line << std::endl;
    		continue;
		}

		double value;
		if (!check_input_value(value_str, &value, line))
		{
			// check_input_value() will print error message
    		continue;
		}

		auto it = _data.lower_bound(date);
		if (it != _data.end() && it->first == date) // we got a match!
		{
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
		else
		{
			if (it == _data.begin()) // no match, but date is before the first date in DB
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (it == _data.end()) // no match and date is after last date in the DB, use last date
			{
				it = std::prev(_data.end());
			}
			else // no match, it returns date closest to date in DB, but we need one before this one
			{
				it--;
			}
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
	}

	input_file.close();
}
