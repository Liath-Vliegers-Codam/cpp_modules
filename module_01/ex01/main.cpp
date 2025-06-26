
#include "./Zombie.hpp"

int main()
{
	int horde_size = 10;

	Zombie *heap_zombie_horde = zombieHorde(horde_size, "Zombianos");

	for (int i = 0; i < horde_size; i++)
	{
		heap_zombie_horde[i].announce();
	}

	std::cout << "Now we kill them all" << std::endl;
	delete[] heap_zombie_horde;

	return (0);
}
