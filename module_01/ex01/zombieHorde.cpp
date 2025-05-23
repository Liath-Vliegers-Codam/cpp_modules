/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:17 by livliege      #+#    #+#                 */
/*   Updated: 2025/05/23 15:06:38 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);

	Zombie *heap_zombies = new Zombie[N];
	
	std::cout << "The zombie horde was created" << std::endl;
	
	for (int i = 0; i < N; i++)
	{
		heap_zombies[i].set_name(name);
	}
	
	std::cout << "All zombies now have a name" << std::endl;
	
	return (heap_zombies);
}
