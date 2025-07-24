#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain default Constructor called" << std::endl;
}

Brain::~Brain() 
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other) 
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) 
{
	std::cout << "Brain copy assignment operator called" << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}
