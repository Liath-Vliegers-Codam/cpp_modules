
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon_of_choice = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_of_choice = &weapon;
	// std::cout << "Weapon was set to " << this->weapon_of_choice->getType() << std::endl;
}

void HumanB::attack()
{
	if (this->weapon_of_choice == NULL)
	{
		std::cout << this->name << " has no weapon and attacks with their fists!" << std::endl;
	}
	else
	{
		std::cout << this->name << " attacked using their " << this->weapon_of_choice->getType() << std::endl;
	}
}
