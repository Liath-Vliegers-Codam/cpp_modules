
#include "Animal.hpp"


Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "Animal";
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

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = other._type;
}
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "An animal makes a sound!" << std::endl;
}

const std::string &Animal::getType() const
{
    return (this->_type);
}
