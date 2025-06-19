#include "ScavTrap.hpp"

/*
You will now create a derived robot.
It will be named ScavTrap and will inherit the constructors and destructor from ClapTrap. 
However, its constructors, destructor and attack() will print different messages.
After all, ClapTraps are aware of their individuality.
Note that proper construction/destruction chaining must be shown in your tests.
When a ScavTrap is created, the program starts by building a ClapTrap. 
Destruction is in reverse order. Why?
ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and must initialize them to:
• Name, which is passed as parameter to a constructor
• Hit points (100), represent the health of the ClapTrap
• Energy points (50)
• Attack damage (20)
ScavTrap will also have its own special capacity: void guardGate();
This member function will display a message informing that ScavTrap is now in Gate keeper mode.
*/


// Constructors and Destructor
ScavTrap::ScavTrap() 
{
	std::cout << "ScavTrap default Constructor called" << std::endl;
	this->_name = "ScavTrap";
}

ScavTrap::ScavTrap(std::string n) 
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->_name = n;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) 
{
	*this = other;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

// Canonical form
ScavTrap &ScavTrap::operator=(const ScavTrap &other) 
{
	(void) other;
	//copy depending on vars;
	return (*this);
}
