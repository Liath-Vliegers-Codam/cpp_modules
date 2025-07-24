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

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->_brain->setIdea(index, idea);
}

const std::string& Dog::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->_brain->getIdea(index));
	static const std::string no_idea = "This animal has no ideas";
	return (no_idea);
}