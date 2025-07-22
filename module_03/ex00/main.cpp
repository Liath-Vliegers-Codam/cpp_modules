
#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");
		
	std::cout << RED << "Testing attack" << DEFAULT << std::endl;
	robot1.attack("target dummy");
	robot2.attack("another target");
	
	robot1.printStats();
	robot2.printStats();
		
	std::cout << RED << "Testing taking damage" << DEFAULT << std::endl;
	robot2.takeDamage(3);
	robot2.printStats();
	robot2.takeDamage(5);
	robot2.printStats();
	robot2.takeDamage(10);
	robot2.printStats();
		
	std::cout << RED << "Testing repair" << DEFAULT << std::endl;
	robot1.beRepaired(5);
	robot2.beRepaired(2);

	robot1.printStats();
	robot2.printStats();
		
	std::cout << RED << "Energy depletion test" << DEFAULT << std::endl;
	for (int i = 0; i < 12; i++)
	{
		robot1.attack("target dummy");
	}
	
	robot1.printStats();
	robot2.printStats();

	return (0);
}
