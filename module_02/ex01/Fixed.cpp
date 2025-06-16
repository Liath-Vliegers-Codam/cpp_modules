/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/02 13:15:19 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/02 13:15:19 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);	
}
