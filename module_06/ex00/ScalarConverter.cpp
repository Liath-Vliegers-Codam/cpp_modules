
#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor is called" << std::endl;
}

// ScalarConverter::ScalarConverter(const ScalarConverter &other) 
// {
// 	std::cout << "ScalarConverter Copy constructor called" << std::endl;
// 	*this = other;
// }


// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor is called" << std::endl;
}

// Getters and Setters


// Member functions
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


bool is_float(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
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

bool is_double(std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
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

ScalarType whichType(std::string input)
{
	if (input.length() == 1)
	{
		if (isdigit(input[0]))
		{
			// std::cout << "input = " << input[0] << std::endl;
			// std::cout << "type is INT (single digit)" << std::endl;
			return (INT);
		}

		int c = static_cast<int>(input[0]);
		if (c > 31 && c < 127)
		{
			// std::cout << "input = " << input[0] << std::endl;
			// std::cout << "type is CHAR" << std::endl;
			// std::cout << "char value = " << c << std::endl;
			return (CHAR);
		}
	}
	else if (input.length() > 1)
	{
		if (is_int(input))
		{
			// std::cout << "input = " << input << std::endl;
			// std::cout << "type is INT (double digits)" << std::endl;
			return (INT);
		}
		if (is_float(input))
		{
			// std::cout << "input = " << input << std::endl;
			// std::cout << "type is FLOAT" << std::endl;
			return (FLOAT);
		}
		if (is_double(input))
		{
			// std::cout << "input = " << input << std::endl;
			// std::cout << "type is DOUBLE" << std::endl;
			return (DOUBLE);
		}
	}
	// std::cout << "input = " << input << std::endl;
	// std::cout << "type is INVALID" << std::endl;
	return (INVALID);
}


static void convert_char(const char &input)
{
	std::cout << "char: '" << input << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(input) << "f" <<std::endl;
	std::cout << "double: " << static_cast<double>(input) <<std::endl;
}

static void convert_int(const std::string &input)
{
	int value = 0;
	try 
	{
		std::size_t pos = 0;
		value = std::stoi(input, &pos, 10);
	}
	catch (const std::invalid_argument &) // not a number
    {
        std::cout << INVALID_INPUT_MESSAGE << std::endl;
        return ;
    }
	catch (const std::out_of_range &)  // overflow or underflow
	{
		std::cout << INVALID_INPUT_MESSAGE << std::endl;
		return ;
	}

	if ((value < 32 && value > 126))
		std::cout << "char: Non displayable" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'"<< std::endl;
	
	std::cout << "int: " << value << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;

}



static void convert_float(const std::string &input)
{
	(void)input;
	std::cout << "float converter function called" << std::endl;
}

static void convert_double(const std::string &input)
{
	(void)input;
	std::cout << "double converter function called" << std::endl;
}


void ScalarConverter::convert(std::string input)
{
	int type = whichType(input);

	if (type == CHAR)
	{
		convert_char(input[0]);
	}
	else if (type == INT)
	{
		convert_int(input);
	}
	else if (type == FLOAT)
	{
		convert_float(input);
	}
	else if (type == DOUBLE)
	{
		convert_double(input);
	}
	else if (type == INVALID)
	{
		std::cout << INVALID_INPUT_MESSAGE << std::endl;
	}
}

// Operators
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) 
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		*this = other;
	}
	return (*this);
}

