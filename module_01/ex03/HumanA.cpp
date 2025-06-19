
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon_of_choice(weapon)
{
	// this->name = name;
	// this->weapon_of_choice = weapon;
}

void HumanA::attack()
{
	std::cout << this->name << " attacked using their " << this->weapon_of_choice.getType() << std::endl;
}
