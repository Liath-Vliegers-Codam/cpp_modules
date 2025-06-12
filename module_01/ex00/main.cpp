/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:12 by livliege      #+#    #+#                 */
/*   Updated: 2025/05/23 14:35:50 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main(void)
{
	Zombie *heap_zombie;

	randomChump("Stackey");
	heap_zombie = newZombie("Heapsters");
	if (!heap_zombie) return (1);
	heap_zombie->announce();
	delete heap_zombie;
	return (0);
}
