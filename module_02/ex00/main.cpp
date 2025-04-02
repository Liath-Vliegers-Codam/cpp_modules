/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/02 13:06:47 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/02 13:06:47 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int 				fixed_value;
		static const int	fractional_bits; //Its value will always be the integer literal 8.
	public:
		Fixed() : fixed_value(0)
		{
			std::cout << "Default constructor called" << std::endl;
		}
		// A copy constructor.
		Fixed(const Fixed& og_copy) : fixed_value(og_copy.fixed_value)
		{
			std::cout << "Copy constructor called" << std::endl;
		}
		// A copy assignment operator overload.
		Fixed& operator=(const Fixed& og_copy)
		{
			if (this != &og_copy)
			{
				fixed_value = og_copy.fixed_value;
			}
			std::cout << "Copy assignment operator called" << std::endl;
			return (*this);
		}
		~Fixed()
		{
			std::cout << "Destructor called" << std::endl;
		}
		int getRawBits( void ) const
		{
			// that returns the raw value of the fixed-point value.
			std::cout << "getRawBits member function called" << std::endl;
		}
		void setRawBits( int const raw )
		{
			// that sets the raw value of the fixed-point number.
			std::cout << "setRawBits member function called" << std::endl;
		}
};

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/*
Should output something similar to:

$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>

*/