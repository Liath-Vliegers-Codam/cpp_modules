/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 17:03:55 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 17:03:55 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon_of_choice(weapon)
{
	this->name = name;
	this->weapon_of_choice = weapon;
}

void HumanA::attack()
{
	std::cout << this->name << " attacked using their " << this->weapon_of_choice.getType() << std::endl;
}
