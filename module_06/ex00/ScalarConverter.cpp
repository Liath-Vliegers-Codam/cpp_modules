
#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
{
	std::cout << "ScalarConverter Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor is called" << std::endl;
}

// Getters and Setters


// Member functions
void ScalarConverter::convert(std::string input)
{
	// std::cout << GREEN << input << DEFAULT << std::endl; // DEBUG

	ScalarType type = whichType(input);

	switch (type)
	{
		case CHAR :
			convert_char(input[0]);
			break;
		case INT:
			convert_int(input);
			break;
		case FLOAT:
			convert_float(input);
			break;
		case DOUBLE:
			convert_double(input);
			break;
		case INVALID:
			std::cout << INVALID_INPUT_MESSAGE << std::endl;
			break;
	}
	// std::cout << std::endl;	// DEBUG
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

std::ostream& operator<<(std::ostream& output_stream, ScalarConverter& other)
{
	(void) other;
	
	output_stream << "*ScalarConverter Class info here*" << std::endl;
	return (output_stream);
}



