/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 19:19:26 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 19:19:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
## Chapter VIII Exercise 05: Harl 2.0
Exercise 05			: Harl 2.0
Turn-in directory 	: ex05/
Files to turn in 	: Makefile
					  main.cpp
					  Harl.{h, hpp}
					  Harl.cpp
Forbidden functions : None

Do you know Harl? We all do, don’t we? In case you don’t, find below the kind of comments Harl makes.
They are classified by levels:

"DEBUG" level:  
Debug messages contain contextual information. They are mostly used for problem diagnosis.  
	Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"

"INFO" level:  
These messages contain extensive information. They are helpful for
tracing program execution in a production environment.  
	Example: "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"

"WARNING" level:  
Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.  
	Example: "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."

"ERROR" level:  
These messages indicate that an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.  
	Example: "This is unacceptable! I want to speak to the manager now."

You are going to automate Harl. It won’t be difficult since he always says the same things. 
You have to create a Harl class with the following private member functions:

- void debug( void );
- void info( void );
- void warning( void );
- void error( void );  

Harl also has a public member function that calls the four member functions above depending on the level passed as a parameter:  
void complain( std::string level );  

The goal of this exercise is to use pointers to member functions. This is not a suggestion. 
Harl has to complain without using a forest of if/else if/else. He doesn’t think twice!

Create and turn in tests to show that Harl complains a lot. You can use the examples
of comments listed above in the subject or choose to use comments of your own.

*/

#include "./Harl.hpp"


int main(void)
{
	Harl harl;

	harl.complain("DEBUG");
	std::cout << std::endl;
	
	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("ERROR");
}