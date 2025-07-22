#pragma once

#include <iostream>
#include <string>
	
	
class Animal 
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string &type);
		virtual ~Animal();

		Animal(const Animal &other);

		Animal &operator=(const Animal &other);

		virtual void makeSound() const;
		const std::string &getType() const;
};
