/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:21 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/31 13:56:32 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Oh no! Someone was bitten! A new zombie named " << this->name << " was born!" << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << "Yes! We've killed another zombie! His name was " << this->name << "..." << std::endl;
}
