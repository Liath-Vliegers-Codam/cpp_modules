#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain default Constructor called" << std::endl;
	this->_name = "Brain";
}

Brain::Brain(std::string n) 
{
	std::cout << "Brain Constructor called" << std::endl;
	this->_name = n;
}

Brain::~Brain() 
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &other) 
{
	*this = other;
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) 
{

	if (this != &other)
	{
		//copy depending on vars;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

