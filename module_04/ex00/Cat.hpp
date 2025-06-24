#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructors and Destructor
		Cat();
		Cat(const Cat &other);
		~Cat();

		// Operator overload
		Cat &operator=(const Cat &other);

		// Member functions
		void makeSound() const;
		const std::string &getType() const;
};
