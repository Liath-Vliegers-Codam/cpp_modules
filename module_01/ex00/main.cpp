
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
