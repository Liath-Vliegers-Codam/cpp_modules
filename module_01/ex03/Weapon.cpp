
#include "Weapon.hpp"

#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
