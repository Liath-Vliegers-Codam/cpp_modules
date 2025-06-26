
#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "./Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		std::string name;
		Weapon 		&weapon_of_choice;

	public:
		HumanA(std::string name, Weapon &weapon);
		void attack();
};

#endif
