/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:17 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/31 13:57:35 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

// This function creates a zombie, names it, and returns it so you can use it outside of the function scope.
Zombie* newZombie(std::string name)
{
	Zombie *heap_zombie;
	
	heap_zombie = new Zombie(name);
	return (heap_zombie);
}
