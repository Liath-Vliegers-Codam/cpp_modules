
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{

	ClapTrap clap_robot("R2D2");
	ScavTrap scav_robot("C3PO");
	FragTrap frag_robot("BB8");

	clap_robot.attack("target dummy");
	clap_robot.takeDamage(3);
	clap_robot.beRepaired(10);

	scav_robot.attack("another target");
	scav_robot.takeDamage(3);
	scav_robot.beRepaired(10);
	scav_robot.guardGate();

	frag_robot.attack("third target");
	frag_robot.takeDamage(3);
	frag_robot.beRepaired(10);
	frag_robot.highFivesGuys();

	return (0);
}
