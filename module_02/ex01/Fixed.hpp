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

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 				_rawBits;
		static const int	_fractionalBits = 8;

	
	public:
		Fixed(void);
		
		Fixed(const int int_value);
		Fixed(const float float_value);

		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);

		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;


};
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

