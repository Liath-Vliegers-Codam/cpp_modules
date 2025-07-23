#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

// Dog::Dog(const Dog &other)
// {
// 	std::cout << "Dog copy constructor called" << std::endl;
// 	delete this->_brain;
// 	*this = other;
// }

// Dog &Dog::operator=(const Dog &other)
// {
// 	std::cout << "Dog copy assignment operator called" << std::endl;
// 	if (this != &other)
// 	{
// 		this->_type = other._type;
// 		// delete this->_brain;
//         this->_brain = new Brain(*(other._brain));
// 	}
// 	return (*this);
// }

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}


void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

// const std::string &Dog::getType() const
// {
//     return (this->_type);
// }
