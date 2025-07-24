#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		~Cat();
		
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);

		void makeSound() const;
		void setIdea(int index, const std::string& idea);
		const std::string& getIdea(int index) const;
};
