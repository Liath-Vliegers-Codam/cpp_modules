
#include "./Zombie.hpp"

// This function creates a zombie, names it, and returns it so you can use it outside of the function scope.
Zombie* newZombie(std::string name)
{
	Zombie* heap_zombie;

	heap_zombie = new Zombie(name);
	if (!heap_zombie)
		return (NULL);
	else
		return (heap_zombie);
}
