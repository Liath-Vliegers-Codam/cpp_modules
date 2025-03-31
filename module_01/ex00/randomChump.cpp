/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:19 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/31 13:57:55 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

// This function creates a zombie, names it, and makes it announce itself.
void randomChump(std::string name)
{
	Zombie stack_zombie(name);
	stack_zombie.announce();
}
