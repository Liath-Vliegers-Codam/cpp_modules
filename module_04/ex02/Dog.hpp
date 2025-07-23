#pragma once

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		~Dog();
		
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);

		void makeSound() const;
};
