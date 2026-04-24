#include "ScalarConverter.hpp"

bool ScalarConverter::is_pseudo_float(std::string input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return (true);
	else
		return (false);
}

bool ScalarConverter::is_pseudo_double(std::string input)
{
	if (input == "nan" || input == "+inf" || input == "-inf")
		return (true);
	else
		return (false);
}

bool ScalarConverter::is_int(std::string input)
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

bool ScalarConverter::is_float(std::string input)
{
	if (is_pseudo_float(input))
		return (true);

	if (input.length() < 2 || input[input.length() - 1] != 'f')
		return (false);

	std::string number = input.substr(0, input.length() - 1);
	
	size_t i = 0;
	size_t dots = 0;

	if (number[i] == '+' || number[i] == '-')
		i++;
	if (number[i] == '.' || number[number.length() - 1] == '.')
		return (false);
	while (i < number.length())
	{
		if (!isdigit(number[i]) && number[i] != '.')
			return (false);
		if (number[i] == '.')
			dots++;
		i++;
	}
	if (dots == 1)
		return (true);
	else
		return (false);
}

bool ScalarConverter::is_double(std::string input)
{
	if (is_pseudo_double(input))
		return (true);

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

ScalarType ScalarConverter::whichType(std::string input)
{
	if (input.length() == 1)
	{
		if (isdigit(input[0]))
			return (INT);

		int c = static_cast<int>(input[0]);
		if (c > 31 && c < 127)
			return (CHAR);
	}
	else if (input.length() > 1)
	{
		if (is_int(input))
			return (INT);
		if (is_float(input))
			return (FLOAT);
		if (is_double(input))
			return (DOUBLE);
	}
	return (INVALID);
}
