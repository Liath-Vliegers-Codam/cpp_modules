/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/02 09:47:21 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/02 09:47:21 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise 06			: Harl filter
Turn-in directory 	: ex06/
Files to turn in 	: Makefile
					  main.cpp
					  Harl.{h, hpp}
					  Harl.cpp
					  Forbidden functions : None

Sometimes you don’t want to pay attention to everything Harl says. 
Implement a system to filter what Harl says depending on the log levels you want to listen to.
Create a program that takes as a parameter one of the four levels. 
It will display all messages from this level and above.   
For example:

$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.
[ ERROR ]
This is unacceptable! I want to speak to the manager now.
$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]

Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off.  
Give the name harlFilter to your executable.  
You must use, and maybe discover, the switch statement in this exercise.  

You can pass this module without doing exercise 06.
*/


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
