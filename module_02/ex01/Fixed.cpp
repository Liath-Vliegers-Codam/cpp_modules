
#include "Fixed.hpp"

Fixed::Fixed()
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
	this->_rawBits = roundf(float_value * (1 << this->_fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) 
{
	if (this != &other)
	{
		this->_rawBits = other._rawBits;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat() const
{
	return ((float)this->_rawBits) / (1 << (this->_fractionalBits));
}

int Fixed::toInt() const
{
	return (this->_rawBits >> this->_fractionalBits); 
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();	// Convert Fixed to float and send to stream
	return (os);			// Return stream reference for chaining
}
