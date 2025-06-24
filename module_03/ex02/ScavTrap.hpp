#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		// Operator overload
		ScavTrap &operator=(const ScavTrap &other);

		void	attack(const std::string &target);
		void	guardGate(void);
};
