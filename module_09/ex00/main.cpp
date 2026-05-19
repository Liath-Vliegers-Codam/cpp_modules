#include "BitcoinExchange.hpp"

bool is_int(std::string input)
{
	size_t i = 0;

	if (input[0] == '-' || input[0] == '+')
		i++;
	while (i < input.length())
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool is_double(std::string input)
{
	if (input.length() < 2)
		return (false);
	
	size_t i = 0;
	size_t dots = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;

	if (input[i] == '.' || input[input.length() - 1] == '.')
		return (false);

	while (i < input.length())
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return (false);
		if (input[i] == '.')
			dots++;
		i++;
	}
	if (dots == 1)
		return (true);
	else
		return (false);
}


void print_map(std::map<std::string, double> data)		// TAKE OUT
{
	std::cout << YELLOW << std::endl;
	std::cout << "--PRINTING MAP:--" << std::endl;
	for (const auto& pair : data)
	{
		std::cout << pair.first << " : " << pair.second << std::endl;
	}
	std::cout << "-----------------" << std::endl;
	std::cout << DEFAULT << std::endl;
}


bool check_date(std::string date, std::string file)
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

	// check if the date is in the future
	if (file == "data_file" && year == datetime->tm_year + 1900)
	{
		if (month > datetime->tm_mon + 1 || (month == datetime->tm_mon + 1 && day > datetime->tm_mday))
		{
			return (false);
		}
	}
	return (true);
}

std::string trim_whitespaces(const std::string &str)
{
	std::string::const_iterator start_it = str.begin();
	std::string::const_iterator end_it = str.end();

	while (start_it != end_it && std::isspace(*start_it))
	{
		start_it++;
	}
	while (end_it != start_it && std::isspace(*(end_it - 1)))
	{
		end_it--;
	}

	std::string trimmed_str = std::string(start_it, end_it);

	return (trimmed_str);
}

void print_subject()
{	
	std::cout << "============================" << std::endl;
	std::cout << "INPUT FILE:" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "date | exchange_rate_str" << std::endl;
	std::cout << "2011-01-03 | 3" << std::endl;
	std::cout << "2011-01-03 | 2" << std::endl;
	std::cout << "2011-01-03 | 1" << std::endl;
	std::cout << "2011-01-03 | 1.2" << std::endl;
	std::cout << "2011-01-09 | 1" << std::endl;
	std::cout << "2012-01-11 | -1" << std::endl;
	std::cout << "2001-42-42" << std::endl;
	std::cout << "2012-01-11 | 1" << std::endl;
	std::cout << "2012-01-11 | 2147483648" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "WHAT WE WANT TO SEE:" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "$> ./btc" << std::endl;
	std::cout << "Error: could not open file." << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "$> ./btc input.txt" << std::endl;
	std::cout << "2011-01-03 => 3 = 0.9" << std::endl;
	std::cout << "2011-01-03 => 2 = 0.6" << std::endl;
	std::cout << "2011-01-03 => 1 = 0.3" << std::endl;
	std::cout << "2011-01-03 => 1.2 = 0.36" << std::endl;
	std::cout << "2011-01-09 => 1 = 0.32" << std::endl;
	std::cout << "Error: not a positive number." << std::endl;
	std::cout << "Error: bad input => 2001-42-42" << std::endl;
	std::cout << "2012-01-11 => 1 = 7.1" << std::endl;
	std::cout << "Error: too large a number." << std::endl;
	std::cout << "$>" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "WHAT WE SEE:" << std::endl;
	std::cout << "============================" << std::endl;
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)*argv;

	try
	{
		BitcoinExchange btc;

		print_subject();

		if (argc != 2)
		{
			std::cerr << "Error: could not open file." << std::endl;
			return (1);
		}
		std::ifstream input_file(argv[1]);
		if (!input_file.is_open())
		{
			std::cerr << "Error: could not open file." << std::endl;
			return (1);
		}

		std::string line;

		std::getline(input_file, line);
		if (line != "date | value")
		{
			std::cerr << RED << "Error : wrong format of the header. Should be [date | value]" << std::endl;
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
			std::string exchange_rate_str = trim_whitespaces(line.substr(split_pos + 1));

			double exchange_rate;
			try
			{
				exchange_rate = stod(exchange_rate_str);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
			
			std::cout << "date : " << date << " exchange_rate : " << exchange_rate << std::endl;

		}

		input_file.close();
	}

	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl;
		return (2);
	}
	

	





	// 	// ===================================================================
	// 	std::string date = line.substr(0, split_pos);

	// 	if (!check_date(date))
	// 	{
	// 		std::cerr << "Error : wrong format of the date in data.csv at line [" << line_nbr << "] : " << line << std::endl;
	// 		continue;
	// 	}

	// 	double exchange_rate_str;
	// 	try
	// 	{
	// 		exchange_rate_str = stof(line.substr(split_pos + 1));
	// 		// std::cout << "exchange_rate_str = " << std::fixed << std::setprecision(2) << exchange_rate_str <<std::endl;

	// 		this->data.insert({date, exchange_rate_str});
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << "Error : wrong format of the exchange_rate_str in data.csv at line [" << line_nbr << "] : " << line << std::endl;
	// 	}
		
	// 	this->data.insert({date, exchange_rate_str});
	// }

	// // print_map(this->data);		// TAKE OUT

	// data_file.close();

	return (0);
}
