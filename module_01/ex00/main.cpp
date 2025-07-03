
#include "./Zombie.hpp"

int main()
{
	Zombie *heap_zombie;

	randomChump("Stackey");
	heap_zombie = newZombie("Heapsters");
	heap_zombie->announce();
	
	delete heap_zombie;

	return (0);
}
