
#include "./Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[ Harl is uneasy.. There is nothing to complaining about ]" << std::endl;
		return (1);
	}

	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string level = argv[1];
	size_t complaint_degree = 10;
	size_t i = 0;

	while (i < 4)
	{
		if (level == levels[i])
		{
			complaint_degree = i;
		}
		i++;
	}
	switch (complaint_degree)
	{
		case 0:
			harl.complain(0);
			break;
		case 1:
			harl.complain(1);
			break;
		case 2:
			harl.complain(2);
			break;
		case 3:
			harl.complain(3);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
