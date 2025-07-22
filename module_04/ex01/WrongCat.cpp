#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
    return;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
    return;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << " NOT Meow Meow!" << std::endl;
}

const std::string &WrongCat::getType() const
{
    return (this->_type);
}
