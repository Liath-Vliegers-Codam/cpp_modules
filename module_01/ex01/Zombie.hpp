
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		void announce();
		void set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
