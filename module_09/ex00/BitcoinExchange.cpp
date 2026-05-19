#include "BitcoinExchange.hpp"


// ===============================================================================================================

// Constructors
BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream data_file("./data.csv");
	if (!data_file.is_open())
	{
		std::cerr << "The [data.csv] file is required for this program, but it is missing or unable to open in this repository";
	}

	data_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore everything until it finds a '\n' (skip the first line (header))
	
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

	// print_map(this->data);		// TAKE OUT

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
		this->data = other.data;
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



