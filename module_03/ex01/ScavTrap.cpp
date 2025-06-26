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


ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default Constructor called" << std::endl;
	this->_name = "ScavTrap";
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hit_points = 100;
}

ScavTrap::ScavTrap(std::string name) 
{
	std::cout << "ScavTrap Constructor called, " << name << " was created" << std::endl;
	this->_name = name;
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hit_points = 100;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &other) 
{
	this->_name = other._name;
	this->_attack_damage = other._attack_damage;
	this->_energy_points = other._energy_points;
	this->_hit_points = other._hit_points;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hit_points == 0)
	{
		std::cout << "ScavTrap " << _name << " can not attack because it is already dead" << std::endl;
	}
	else if (_energy_points == 0)
	{
		std::cout << "ScavTrap " << _name << " can not attack because it has no energy points left.." << std::endl;
	}
	else
	{
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}

}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in GateKeeper Mode!" << std::endl;
}