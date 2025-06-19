
#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "./Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		Weapon		*weapon_of_choice;
		std::string name;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void);
};

#endif
