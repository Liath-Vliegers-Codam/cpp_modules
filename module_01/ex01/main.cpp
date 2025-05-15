/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:12 by livliege      #+#    #+#                 */
/*   Updated: 2025/05/15 17:23:15 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main(void)
{
	int		i = 0;
	int		horde_size = 10;
	Zombie	*heap_zombie_horde = zombieHorde(horde_size, "Heapsters");
	
	if (!heap_zombie_horde)
		return (1);
	
	while (i < horde_size)
	{
		heap_zombie_horde[i].announce();
		i++;
	}
	
	std::cout << "Now we kill them all" << std::endl;
	delete[] heap_zombie_horde;
	
	return (0);
}
