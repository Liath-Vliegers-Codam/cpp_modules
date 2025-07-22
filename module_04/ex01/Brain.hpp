#pragma once

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string _name;

	public:
		Brain();
		Brain(std::string);
		~Brain();

		// Copy constructor
		Brain(const Brain &other);
		// Operator overload
		Brain &operator=(const Brain &other);
};
