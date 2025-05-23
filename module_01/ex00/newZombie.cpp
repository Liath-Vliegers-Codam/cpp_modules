/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:17 by livliege      #+#    #+#                 */
/*   Updated: 2025/05/23 14:31:34 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

// This function creates a zombie, names it, and returns it so you can use it outside of the function scope.
Zombie* newZombie(std::string name)
{
	Zombie *heap_zombie;
	
	heap_zombie = new Zombie(name); 
	if (!heap_zombie)
		return (NULL);
	else
		return (heap_zombie);
}
