
#include "./Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra jalapenos for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra jalapenos costs more money. ";
	std::cout << "You didn’t put enough jalapenos in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra jalapenos for free.";
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	// Harl also has a public member function that calls the four member functions above depending on the level passed as a parameter
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	function_ptr complaining[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
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
	if (complaint_degree == 10)
	{
		std::cout << "Not a valid complaint level!" << std::endl;
	}
	else
	{
		(this->*complaining[complaint_degree])();
	}
}
