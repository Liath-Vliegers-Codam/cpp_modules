/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:17 by livliege      #+#    #+#                 */
/*   Updated: 2025/05/15 17:23:30 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie *heap_zombies = new Zombie[N];
	
	if(!heap_zombies)
		return (NULL);
	if (N <= 0)
		return (NULL);
	
	std::cout << "Zombie horde was created" << std::endl;
	while (i < N)
	{
		heap_zombies[i] = Zombie(name);
		i++;
	}
	std::cout << "All zombies now have a name" << std::endl;
	
	return (heap_zombies);
}
