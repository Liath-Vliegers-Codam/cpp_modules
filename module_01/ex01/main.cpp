/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:12 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/31 16:27:25 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*

Exercise : 01
Moar brainz!

Turn-in directory	: ex01/
Files to turn in	: Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, zombieHorde.cpp
Forbidden functions : None

Time to create a horde of Zombies!
Implement the following function in the appropriate file:
	Zombie* zombieHorde( int N, std::string name );
It must allocate N Zombie objects in a single allocation. 
Then, it must initialize the zombies, giving each of them the name passed as a parameter. 
The function returns a pointer to the first zombie.
Implement your own tests to ensure that your zombieHorde() function works as expected. 
Try calling announce() for each of the zombies.
Do not forget to use delete to deallocate all the zombies and check for memory leaks.

*/

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
