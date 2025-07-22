#include "FragTrap.hpp"

// Constructors and Destructor
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default Constructor called" << std::endl;
	this->_name = "FragTrap";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) 
{
	std::cout << "FragTrap Constructor called, " << name << " was created" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::~FragTrap() 
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) 
{
	this->_name = other._name;
	this->_attack_damage = other._attack_damage;
	this->_energy_points = other._energy_points;
	this->_hit_points = other._hit_points;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (_hit_points == 0)
	{
		std::cout << "FragTrap " << _name << " can not attack because it is already dead" << std::endl;
	}
	else if (_energy_points == 0)
	{
		std::cout << "FragTrap " << _name << " can not attack because it has no energy points left.." << std::endl;
	}
	else
	{
		_energy_points--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " wants to high five the other robots!" << std::endl;
}

void FragTrap::printStats() const
{
	std::cout << YELLOW;
	std::cout << _name << " Stats:" << std::endl;
	std::cout << GREEN;
	std::cout << "Hit points	= " << _hit_points << std::endl;
	std::cout << "Energy points	= " << _energy_points << std::endl;
	std::cout << "Attack damage	= " << _attack_damage << std::endl;
	std::cout << DEFAULT;
}