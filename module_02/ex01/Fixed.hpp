
#include <iostream>
#include <cmath>

class Fixed
{
   private:
	int 				_rawBits;
	static const int	_fractionalBits = 8;

   public:
	Fixed();
	Fixed(const int int_value);
	Fixed(const float float_value);
	Fixed(const Fixed &other);

	Fixed &operator=(const Fixed &other);

	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
