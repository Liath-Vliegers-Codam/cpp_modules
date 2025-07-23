#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);

		void makeSound() const;
};
