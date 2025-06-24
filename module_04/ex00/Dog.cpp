#include "Dog.hpp"


Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

// Operator overload
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Member functions
void Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}

const std::string &Dog::getType( void ) const
{
    return (this->_type);
}
