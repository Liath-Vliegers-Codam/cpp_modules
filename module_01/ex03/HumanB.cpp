/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 17:03:59 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 17:03:59 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
