/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:12 by livliege      #+#    #+#                 */
/*   Updated: 2025/05/23 15:10:37 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main(void)
{
	int		horde_size = 10;

	Zombie	*heap_zombie_horde = zombieHorde(horde_size, "Zombianos");
	
	for (int i = 0; i < horde_size; i++)
	{
		heap_zombie_horde[i].announce();
	}
	
	std::cout << "Now we kill them all" << std::endl;
	delete[] heap_zombie_horde;

	return (0);
}
