#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors and Destructor
		Dog();
		Dog(const Dog &other);
		~Dog();

		// Operator overload
		Dog &operator=(const Dog &other);

		// Member functions
		void makeSound(void) const;
		const std::string &getType(void) const;
};
