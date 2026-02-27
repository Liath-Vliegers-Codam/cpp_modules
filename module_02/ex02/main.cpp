
#include "Fixed.hpp"

int main()
{	
	std::cout << "------------== Testing arithmetic operators ------------==" << std::endl;

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

	std::cout << "------------== Testing comparison operators ------------==" << std::endl;
	
	std::cout << std::boolalpha;
	std::cout << "a == b:	" << (a == b) << std::endl;
	std::cout << "a != b:	" << (a != b) << std::endl;
	std::cout << "a > b:	" << (a > b) << std::endl;
	std::cout << "a < b:	" << (a < b) << std::endl;
	std::cout << "a >= b:	" << (a >= b) << std::endl;
	std::cout << "a <= b:	" << (a <= b) << std::endl;

	std::cout << "------------== Testing increment/decrement operators ------------==" << std::endl;

	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << "------------== Testing min/max functions ------------==" << std::endl;

	Fixed x(10.5f);
	Fixed y(3.25f);
	Fixed z(-2.75f);

	std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
		
	std::cout << "Fixed::min(x, y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "Fixed::max(x, y) = " << Fixed::max(x, y) << std::endl;
	std::cout << "Fixed::min(y, z) = " << Fixed::min(y, z) << std::endl;
	std::cout << "Fixed::max(y, z) = " << Fixed::max(y, z) << std::endl;
	std::cout << "Fixed::min(x, z) = " << Fixed::min(x, z) << std::endl;
	std::cout << "Fixed::max(x, z) = " << Fixed::max(x, z) << std::endl;


	std::cout << "------------== Testing const min/max functions ------------==" << std::endl;

	const Fixed const_a(15.75f);
	const Fixed const_b(15.75f);
	const Fixed const_c(8.125f);
		
	std::cout << "const_a = " << const_a << ", const_b = " << const_b << ", const_c = " << const_c << std::endl;
		
	std::cout << "Fixed::min(const_a, const_b) = " << Fixed::min(const_a, const_b) << std::endl;
	std::cout << "Fixed::max(const_a, const_c) = " << Fixed::max(const_a, const_c) << std::endl;
	std::cout << "Fixed::min(const_b, const_c) = " << Fixed::min(const_b, const_c) << std::endl;
		
	return (0);
}


// int main()
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

