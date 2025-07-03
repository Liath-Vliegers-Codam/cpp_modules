
#include "./Zombie.hpp"

Zombie::Zombie() 
{ 
	std::cout << "Oh no! Someone was bitten!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Yes! We've killed another zombie! His name was " << this->name << "..." << std::endl;
}

void Zombie::announce() 
{ 
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

void Zombie::set_name(std::string name)
{
	this->name = name;
	std::cout << "A zombie has a name now: " << this->name << std::endl;
}
