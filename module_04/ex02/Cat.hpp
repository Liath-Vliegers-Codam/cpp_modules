#pragma once

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *_brain;

	public:
		Cat();
		~Cat();
		
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);

		void makeSound() const;
};
