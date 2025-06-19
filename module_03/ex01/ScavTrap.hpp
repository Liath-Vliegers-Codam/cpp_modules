#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string _name;

	public:
		ScavTrap();
		ScavTrap(std::string);
		~ScavTrap();

		// Copy constructor
		ScavTrap(const ScavTrap &other);
		// Operator overload
		ScavTrap &operator=(const ScavTrap &other);
};
