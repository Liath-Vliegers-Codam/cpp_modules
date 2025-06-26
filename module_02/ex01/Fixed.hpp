
#include <iostream>
#include <cmath>

class Fixed
{
   private:
	int _rawBits;
	static const int _fractionalBits = 8;

   public:
	// Constructor overloads
	Fixed();					 // Default constructor
	Fixed(const int int_value);		 // Int constructor
	Fixed(const float float_value);	 // Float constructor
	Fixed(const Fixed &other);		 // Copy constructor

	// Assignment operator overloads
	Fixed &operator=(const Fixed &other);

	// Deconstructor
	~Fixed();

	// Member functions
	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
