
#include "./Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[ Harl is uneasy.. There is nothing to complaining about ]" << std::endl;
		return (1);
	}

	Harl harl;
	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "DO_NOT_REMOVE"};
	std::string level = argv[1];
	int complaint_degree = -1;
	size_t i = 0;

	while (levels[i] != "DO_NOT_REMOVE")
	{
		if (level == levels[i])
		{
			complaint_degree = i;
		}
		i++;
	}
	if (complaint_degree >= 0)
		harl.complain(complaint_degree);
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
