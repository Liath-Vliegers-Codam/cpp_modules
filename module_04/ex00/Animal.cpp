
#include "Animal.hpp"


// Default constructor
Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "Unknown";
}
Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called, a " << type << " was created" << std::endl;
	this->_type = type;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = other._type;
}
// Operator overload
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Member functions
void Animal::makeSound(void) const
{
	std::cout << "An animal makes a sound!" << std::endl;
}

const std::string &Animal::getType(void) const
{
    return (this->_type);
}
