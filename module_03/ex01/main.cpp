
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap_robot("R2D2");
	ScavTrap scav_robot("C3PO");
		
	std::cout << RED << "Testing attack" << DEFAULT << std::endl;
	clap_robot.attack("target dummy");
	clap_robot.attack("another target");

	scav_robot.attack("target dummy");
	scav_robot.attack("another target");

	clap_robot.printStats();
	scav_robot.printStats();
		
	std::cout << RED << "Testing taking damage" << DEFAULT << std::endl;
	scav_robot.takeDamage(3);
	scav_robot.printStats();
	scav_robot.takeDamage(5);
	scav_robot.printStats();
	scav_robot.takeDamage(10);
	scav_robot.printStats();
		
	std::cout << RED << "Testing repair" << DEFAULT << std::endl;
	clap_robot.beRepaired(5);
	scav_robot.beRepaired(2);

	clap_robot.printStats();
	scav_robot.printStats();
		
	std::cout << RED << "Energy depletion test" << DEFAULT << std::endl;
	for (int i = 0; i < 10; i++)
	{
		clap_robot.attack("target dummy");
	}
	for (int i = 0; i < 50; i++)
	{
		scav_robot.attack("target dummy");
	}
	
	clap_robot.printStats();
	scav_robot.printStats();

	std::cout << RED << "Gate keeper mode" << DEFAULT << std::endl;
	scav_robot.guardGate();

	return (0);
}
