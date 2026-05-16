#include "BitcoinExchange.hpp"


void print_map(std::map<std::string, double> data)
{
	for (const auto& pair : data)
	{
		std::cout << pair.first << " : " << pair.second << std::endl;
	}
}

// 2009-03-15

// 0123456789


// 2009-01-02,0

bool check_date(std::string date)
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

		// std::cout << "year: " << year << std::endl;
		// std::cout << "month: " << month << std::endl;
		// std::cout << "day: " << day << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << RED << e.what() << DEFAULT << '\n';
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

	// // check if the date is before January 3, 2009
	// if (year == 2009)
	// {
	// 	if (month < 1 || (month == 1 && day < 3))
	// 	{
	// 		return (false);
	// 	}
	// }


	// check if the date is in the future
	if (year == datetime->tm_year + 1900)
	{
		if (month > datetime->tm_mon + 1 || (month == datetime->tm_mon + 1 && day > datetime->tm_mday))
		{
			return (false);
		}
	}

	return (true);
}



// ===============================================================================================================

// Constructors
BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream data_file("./data.csv");
	if (!data_file.is_open())
	{
		std::cerr << "The [data.csv] file is required for this program, but it is missing or unable to open in this repository";
	}

	data_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip the first line (header)
	
	std::string line;
	int line_nbr = 1;

	while (std::getline(data_file, line))
	{
		line_nbr++;

		size_t split_pos = line.find(',');
		if (split_pos == std::string::npos)
		{
			std::cerr << "Error : wrong format in data.csv at line [" << line_nbr << "] : " << line << std::endl;
			continue;
		}
		
		std::string date = line.substr(0, split_pos);

		if (!check_date(date))
		{
			std::cerr << "Error : wrong format of the date in data.csv at line [" << line_nbr << "] : " << line << std::endl;
			continue;
		}

		double value;
		try
		{
			value = stof(line.substr(split_pos + 1));
			// std::cout << "value = " << std::fixed << std::setprecision(2) << value <<std::endl;

			this->data.insert({date, value});
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error : wrong format of the value in data.csv at line [" << line_nbr << "] : " << line << std::endl;
		}
		
		this->data.insert({date, value});
	}

	print_map(this->data);

	data_file.close();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
	std::cout << "BitcoinExchange copy constructor is called" << std::endl;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << "BitcoinExchange destructor is called" << std::endl;
}

// Getters and Setters

// Member functions


// Overload operators
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		*this = other;
		std::cout << "BitcoinExchange copy assignment is called" << std::endl;
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

