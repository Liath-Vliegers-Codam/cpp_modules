#include "Cat.hpp"
		
// Constructors and Destructor
Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

// Operator overload
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Member functions
void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}

const std::string &Cat::getType() const
{
    return (this->_type);
}