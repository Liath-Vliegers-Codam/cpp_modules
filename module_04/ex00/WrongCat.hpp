#pragma once

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors and Destructor
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();

		// Operator overload
		WrongCat &operator=(const WrongCat &other);

		// Member functions
		void makeSound(void) const;
		const std::string &getType(void) const;
};