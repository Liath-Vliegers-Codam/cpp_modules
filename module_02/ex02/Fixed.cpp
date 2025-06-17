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
	// std::cout << "Default constructor called" << std::endl;
}

// this function converts an integer to a fixed-point representation
Fixed::Fixed(const int int_value)
{
	this->_rawBits = int_value << this->_fractionalBits;
	// std::cout << "Int constructor called" << std::endl;
}

// this function converts a float to a fixed-point representation
Fixed::Fixed(const float float_value)
{
	this->_rawBits = roundf(float_value * (2 << (this->_fractionalBits - 1)));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// this->_rawBits = other._rawBits;
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_rawBits = other._rawBits;
		// std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	// std::cout << "setRawBits member function called" << std::endl;
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
	os << fixed.toFloat();	// Convert Fixed to float and send to stream
	return (os);			// Return stream reference for chaining
}

// Comparison operator overloads
// • The 6 comparison operators : >, <, >=, <=, == and !=.
bool Fixed::operator>(const Fixed &other) const
{
	if (this->_rawBits > other._rawBits)
		return (true);
	else 
		return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->_rawBits < other._rawBits)
		return (true);
	else 
		return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->_rawBits >= other._rawBits)
		return (true);
	else 
		return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->_rawBits <= other._rawBits)
		return (true);
	else 
		return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->_rawBits == other._rawBits)
		return (true);
	else 
		return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->_rawBits != other._rawBits)
		return (true);
	else 
		return (false);
}



// Arithmetic operator overloads
// • The 4 arithmetic operators: +, -, *, and /.
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result._rawBits = _rawBits + other._rawBits;

	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result._rawBits = _rawBits - other._rawBits;

	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result._rawBits = (_rawBits * other._rawBits) >> _fractionalBits;

	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	result._rawBits = (_rawBits << _fractionalBits) / other._rawBits;

	return result;
}

/*
	The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators, 
	that will increase or decrease the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.

	The smallest representable value (ε - epsilon) in your fixed-point system is the precision limit of your Fixed class.

	What is ε (epsilon)?
		In your Fixed class with 8 fractional bits:
		ε = 1 / (2^8) = 1/256 ≈ 0.00390625

	This is the smallest positive difference you can represent between two Fixed numbers.

	How It Works
	Your _rawBits stores the value as: actual_value × 2^8

	So when you increment _rawBits by 1:

	You're adding 1 / 2^8 to the actual floating-point value
	This is exactly ε.

		
	Pre-increment (++variable)

		No parameters - distinguishes it from post-increment
		Increments first, then returns the incremented value
		Returns a reference (Fixed&) to the current object for efficiency
		Increases by the smallest representable value (1 in raw bits = ε)

	Post-increment (variable++)
		￼
		int parameter - dummy parameter to distinguish from pre-increment
		Returns old value first, then increments
		Returns by value (Fixed) - must return the old state
		Less efficient due to temporary object creation

*/

	Fixed& Fixed::operator++()
	{
		++_rawBits;
		return (*this);
	}

	Fixed& Fixed::operator--()
	{
		--_rawBits;
		return (*this);
	}

	Fixed Fixed::operator++(int)
	{
		Fixed old(*this);

		++_rawBits;

		return (old);
	}
	
	Fixed Fixed::operator--(int)
	{
		Fixed old(*this);

		--_rawBits;

		return (old);
	}
	
	// • A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
	Fixed& Fixed::min(Fixed& one, Fixed& two)
	{
		return ((one < two) ? one : two);
	}

	// • A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
	const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
	{
		return ((one < two) ? one : two);
	}
	
	// • A static member function max that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
	Fixed& Fixed::max(Fixed& one, Fixed& two)
	{
		return ((one > two) ? one : two);
	}
	
	// • A static member function max that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.
	const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
	{
		return ((one > two) ? one : two);
	}
