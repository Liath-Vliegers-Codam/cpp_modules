#pragma once

#include <iostream>
#include <string>

class Animal 
{
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal(); // Virtual destructor for proper cleanup

		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		virtual void makeSound() const; // Virtual enables polymorphism
		const std::string &getType() const;
};
