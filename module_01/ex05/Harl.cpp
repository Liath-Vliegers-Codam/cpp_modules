/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 19:53:06 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 19:53:06 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

void Harl::debug(void)
{
// "DEBUG" level:  
// Debug messages contain contextual information. They are mostly used for problem diagnosis.  
// Example: "I love having extra jalapenos for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	std::cout << "DEBUG level" << std::endl;	
	std::cout << "I love having extra jalapenos for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;	
}
void Harl::info(void)
{
// "INFO" level:  
// These messages contain extensive information. They are helpful for tracing program execution in a production environment.  
// Example: "I cannot believe adding extra jalapenos costs more money. You didn’t put enough jalapenos in my burger! If you did, I wouldn’t be asking for more!"
	std::cout << "INFO level" << std::endl;
	std::cout << "I cannot believe adding extra jalapenos costs more money. You didn’t put enough jalapenos in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
// "WARNING" level:  
// Warning messages indicate a potential issue in the system. However, it can be handled or ignored.  
// Example: "I think I deserve to have some extra jalapenos for free. I’ve been coming for years, whereas you started working here just last month."
	std::cout << "WARNING level" << std::endl;
	std::cout << "I think I deserve to have some extra jalapenos for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error(void)
{
// "ERROR" level:  
// These messages indicate that an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention.  
// Example: "This is unacceptable! I want to speak to the manager now."
	std::cout << "ERROR level" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
// Harl also has a public member function that calls the four member functions above depending on the level passed as a parameter
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	t_func toxic[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
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
		(this->*toxic[complaint_degree])();
	}
}
