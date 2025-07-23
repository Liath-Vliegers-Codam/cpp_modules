#pragma once

#include <iostream>
#include <string>


// WrongCat makes a WrongAnimal sound because it inherits from WrongAnimal.
// The WrongAnimal class is a base class that does not have a virtual function for makeSound
// so the WrongCat class does not override it properly.

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		~WrongAnimal();
		
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);

		void makeSound() const;
		const std::string &getType() const;
};