#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
{
	*this = other;
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " can not attack because it is already dead" << std::endl;
	}
	else if (_energy_points == 0)
	{
		std::cout << "ClapTrap " << _name << " can not attack because it has no energy points left.." << std::endl;
	}
	else
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " can not take damage because it is already dead." << std::endl;
	
	}
	else if (amount >= _hit_points)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage and has been killed." << std::endl;
	}
	else
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage, but is still holding on.. " << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " can not heal because it is already dead." << std::endl;
	
	}
	else if (_energy_points == 0)
	{
		std::cout << "ClapTrap " << _name << " can not heal because it has no energy points left.." << std::endl;
	}
	else
	{
		_energy_points--;
		_hit_points += amount;
		std::cout << "ClapTrap " << _name << " heals itself with " << amount << " points!" << std::endl;
	}
}

void ClapTrap::printStats() const
{
	std::cout << YELLOW;
	std::cout << _name << " Stats:" << std::endl;
	std::cout << GREEN;
	std::cout << "Hit points	= " << _hit_points << std::endl;
	std::cout << "Energy points	= " << _energy_points << std::endl;
	std::cout << "Attack damage	= " << _attack_damage << std::endl;
	std::cout << DEFAULT;
}
