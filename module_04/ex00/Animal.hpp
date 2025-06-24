#pragma once

#include <iostream>
#include <string>
	
	
class Animal 
{
	protected:
		std::string _type;
	public:
		// Constructors and Destructor
		Animal();
		Animal(std::string name);
		~Animal();

		// Copy constructor
		Animal(const Animal &other);
		// Operator overload
		Animal &operator=(const Animal &other);

		// Member functions
		virtual void makeSound(void) const;
		const std::string &getType(void) const;
};
