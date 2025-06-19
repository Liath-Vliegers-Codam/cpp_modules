
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

// this function converts an integer to a fixed-point representation
Fixed::Fixed(const int int_value)
{
	this->_rawBits = int_value << this->_fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

// this function converts a float to a fixed-point representation
Fixed::Fixed(const float float_value)
{
	this->_rawBits = roundf(float_value * (2 << (this->_fractionalBits - 1)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// its good practise to link the copy constructor to the copy assignment operator, this ensures that there will be no issues while copying.
// now when you call the copy constructor, it will use the copy assignment operator to copy the data.
Fixed& Fixed::operator=(const Fixed &other) 
{
	if (this != &other)
	{
		this->_rawBits = other._rawBits;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits) / (2 << (this->_fractionalBits - 1));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractionalBits); 
}

/*
	std::ostream & 		: Returns a reference to an output stream, enabling operator chaining
	operator<< 			: Overloads the left - shift operator for output operations
	std::ostream &os 	: Reference to the output stream(like std::cout, std::cerr, file streams, etc.)
	const Fixed &fixed	: Constant reference to the Fixed object being output (avoids unnecessary copying)

	1. Converts the Fixed object to a float using the toFloat() member function
	2. Sends that float value to the output stream using the built-in << operator for floats
	3. Returns the stream reference to enable chaining operations

	This operator is defined as a free function (outside the class) rather than a member function because:

	The left operand is std::ostream, not Fixed
	If it were a member, you'd have to write fixed << std::cout instead of std::cout << fixed
	This maintains the natural left-to-right reading order
	This is a standard pattern in C++ for making custom types work seamlessly with the stream I/O system.
*/

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();	// Convert Fixed to float and send to stream
	return (os);			// Return stream reference for chaining
}
