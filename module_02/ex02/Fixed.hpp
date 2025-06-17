/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/02 13:15:22 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/02 13:15:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed
{
   private:
	int _rawBits;
	static const int _fractionalBits = 8;

   public:
	// Constructor overloads
	Fixed(void);					 // Default constructor
	Fixed(const int int_value);		 // Int constructor
	Fixed(const float float_value);	 // Float constructor
	Fixed(const Fixed &other);		 // Copy constructor

	// Assignment operator overloads (calls copy constructor)
	Fixed &operator=(const Fixed &other);

	// Deconstructor
	~Fixed(void);

	// Member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;


// Function overloading provides a clean, intuitive interface that allows your custom types to behave like built-in types, 
// making your code more readable and maintainable.

// added in this exersize:


	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& one, Fixed& two);
	static const Fixed& min(const Fixed& one, const Fixed& two);
	static Fixed& max(Fixed& one, Fixed& two);
	static const Fixed& max(const Fixed& one, const Fixed& two);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

