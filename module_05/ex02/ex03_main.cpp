/*
	Exercise : 03			At least this beats coffee-making
	Turn-in directory: 		ex03/
	Files to turn in: 		Files from previous exercises + Intern.{h, hpp}, Intern.cpp
	Forbidden functions: 	None
	
	Since filling out forms all day would be too cruel for our bureaucrats, interns exist to take on this tedious task. 
	In this exercise, you must implement the Intern class. 
	The intern has no name, no grade, and no unique characteristics. 
	The only thing bureaucrats care about is that they do their job.
	However, the intern has one key ability: the makeForm() function. 
	This function takes two strings as parameters: the first one represents the name of a form, and the second one represents the target of the form. 
	It returns a pointer to a AForm object (corresponding to the form name passed as a parameter), with its target initialized to the second parameter.
	
	It should print something like:
	Intern creates <form>
	If the provided form name does not exist, print an explicit error message.

	You must avoid unreadable and messy solutions, such as using an excessive if/elseif/else structure. 
	This kind of approach will not be accepted during the evaluation process. 
	You’re not in the Piscine (pool) anymore. As usual, you must test everything to ensure it works as expected.
	For example, the following code creates a RobotomyRequestForm targeted at "Bender":
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
*/



// REMOVE FormNotFound in AForm.hpp (EX02) ONLY FOR EX03


#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    const char* names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "unknown form"
    };

    const char* targets[] = {
        "home",
        "Bender",
        "Marvin",
        "Nobody"
    };

    for (int i = 0; i < 4; ++i)
    {
        std::cout << "\n-- Requesting form: " << names[i] << " (target: " << targets[i] << ") --" << std::endl;
        AForm* form = someRandomIntern.makeForm(names[i], targets[i]);
        if (!form)
        {
            std::cout << "Intern failed to create form: " << names[i] << std::endl;
            continue;
        }

        std::cout << *form << std::endl;

        try
        {
            boss.signForm(*form);
        }
        catch (std::exception& e)
        {
            std::cout << "Sign failed: " << e.what() << std::endl;
        }

        try
        {
            boss.executeForm(*form);
        }
        catch (std::exception& e)
        {
            std::cout << "Execute failed: " << e.what() << std::endl;
        }

        delete form;
    }

    return (0);
}