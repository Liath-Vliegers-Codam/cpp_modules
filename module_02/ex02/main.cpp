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

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) + Fixed(2));
	Fixed const c(Fixed(5.05f) - Fixed(2));
	Fixed const d(Fixed(5.05f) * Fixed(2));
	Fixed const e(Fixed(5.05f) / Fixed(2));
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	
	a.operator==(b) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
	a.operator!=(b) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
	a.operator>(b) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
	a.operator<(b) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
	a.operator>=(b) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
	a.operator<=(b) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;

	return 0;
}


// int main(void)
// {
// 	Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;
// 	return 0;
// }

/*
	Should output something similar to:

	$ >./ a.out 
	0 
	0.00390625 
	0.00390625 
	0.00390625 
	0.0078125 
	10.1016 
	10.1016 
	$ >
*/

