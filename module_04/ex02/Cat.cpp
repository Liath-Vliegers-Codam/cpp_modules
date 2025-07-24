#include "Cat.hpp"
		
Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->_brain->setIdea(index, idea);
}

const std::string& Cat::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->_brain->getIdea(index));
	static const std::string no_idea = "This animal has no ideas";
	return (no_idea);
}
