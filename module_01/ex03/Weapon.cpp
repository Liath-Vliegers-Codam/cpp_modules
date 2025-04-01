/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 17:00:43 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 17:00:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon(void)
{

}

const std::string &Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
