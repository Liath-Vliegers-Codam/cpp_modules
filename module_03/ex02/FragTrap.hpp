#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();

		FragTrap &operator=(const FragTrap &other);

		void	attack(const std::string &target);
		void	highFivesGuys();

		void	printStats() const;
};
