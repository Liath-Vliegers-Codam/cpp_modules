#pragma once

#include <iostream>
#include <string>

#define BLACK   "\033[30m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define DEFAULT "\033[0m"

class ClapTrap 
{
	private:
		std::string _name;
		unsigned int _hit_points;
		unsigned int _energy_points;
		unsigned int _attack_damage;

	public:
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void printStats() const;
};
