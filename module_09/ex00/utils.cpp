#include "BitcoinExchange.hpp"
#include "utils.hpp"

bool is_int(std::string input)
{
	if (input == "")
	{
		return (false);
	}

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

	if (input == "")
	{
		return (false);
	}

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
