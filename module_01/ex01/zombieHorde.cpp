
#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);

	Zombie* heap_zombies = new Zombie[N];

	std::cout << "The zombie horde was created" << std::endl;

	for (int i = 0; i < N; i++)
	{
		heap_zombies[i].set_name(name);
	}

	std::cout << "All zombies now have a name" << std::endl;

	return (heap_zombies);
}
