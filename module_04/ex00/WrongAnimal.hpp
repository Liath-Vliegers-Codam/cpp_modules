#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		// Constructors and Destructor
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();

		// Operator overload
		WrongAnimal &operator=(const WrongAnimal &other);

		// Member functions
		void makeSound() const;
		const std::string	&getType() const;
};