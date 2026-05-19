#include "BitcoinExchange.hpp"


void print_map(std::map<std::string, double> data)		// TAKE OUT
{
	for (const auto& pair : data)
	{
		std::cout << pair.first << " : " << pair.second << std::endl;
	}
}


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
	if (year == datetime->tm_year + 1900)
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


int main(int argc, char *argv[])
{
	BitcoinExchange bitcoinExchange;

	std::cout << "============================" << std::endl;
	std::cout << "WHAT WE WANT TO SEE:" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "$> ./btc" << std::endl;
	std::cout << "Error: could not open file." << std::endl;
	std::cout << "============================" << std::endl;
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



	if (argc != 2)
	{
		std::cerr << "Please make sure you run this program with the path to an input file" << std::endl;
	}
	std::ifstream input_file(argv[1]);
	if (!input_file.is_open())
	{
		std::cerr << "An input file is required for this program, but it is missing or unable to open in this repository";
	}

	std::string line;
	// int line_nbr = 1;

	while (std::getline(input_file, line))
	{
		// line_nbr++;

		size_t split_pos = line.find('|');
		if (split_pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim_whitespaces(line.substr(0, split_pos));
		std::string value = trim_whitespaces(line.substr(split_pos + 1));

		std::map<std::string, double> input_data;

	
	}





	// 	// trimm spaces
		




	// 	// ===================================================================
	// 	std::string date = line.substr(0, split_pos);

	// 	if (!check_date(date))
	// 	{
	// 		std::cerr << "Error : wrong format of the date in data.csv at line [" << line_nbr << "] : " << line << std::endl;
	// 		continue;
	// 	}

	// 	double value;
	// 	try
	// 	{
	// 		value = stof(line.substr(split_pos + 1));
	// 		// std::cout << "value = " << std::fixed << std::setprecision(2) << value <<std::endl;

	// 		this->data.insert({date, value});
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << "Error : wrong format of the value in data.csv at line [" << line_nbr << "] : " << line << std::endl;
	// 	}
		
	// 	this->data.insert({date, value});
	// }

	// // print_map(this->data);		// TAKE OUT

	// data_file.close();

	// return (0);
}
