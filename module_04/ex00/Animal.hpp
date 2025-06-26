#pragma once

#include <iostream>
#include <string>
	
	
class Animal 
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string name);
		virtual ~Animal();

		Animal(const Animal &other);

		Animal &operator=(const Animal &other);

		virtual void makeSound() const;
		const std::string &getType() const;
};
