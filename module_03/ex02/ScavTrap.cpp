#include "ScavTrap.hpp"

// Constructors and Destructor
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