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


// #include "Intern.hpp"
// #include "AForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "Bureaucrat.hpp"

// int main()
// {
// 	Intern someRandomIntern;
// 	AForm *shrub_form;
// 	AForm *robot_form;
// 	AForm *president_form;
// 	AForm *invalid_form;

// 	std::cout << YELLOW << "=========== shrubbery creation test ===========" << DEFAULT << std::endl;
// 	try
// 	{
// 		shrub_form = someRandomIntern.makeForm("shrubbery creation", "Home");
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Intern failed to create form: " << e.what() << std::endl;
// 	}

// 	std::cout << YELLOW << "=========== robotomy request test ===========" << DEFAULT << std::endl;
// 	try
// 	{
// 		robot_form = someRandomIntern.makeForm("robotomy request", "Bender");
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Intern failed to create form: " << e.what() << std::endl;
// 	}

// 	std::cout << YELLOW << "=========== presidential pardon test ===========" << DEFAULT << std::endl;
// 	try
// 	{
// 		president_form = someRandomIntern.makeForm("presidential pardon", "Marvin");
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Intern failed to create form: " << e.what() << std::endl;
// 	}

// 	std::cout << YELLOW << "=========== invalid form test ===========" << DEFAULT << std::endl;
// 	try
// 	{
// 		invalid_form = someRandomIntern.makeForm("invalid form", "Unknown");
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Intern failed to create form: " << e.what() << std::endl;
// 	}

//     // Intern someRandomIntern;
//     // Bureaucrat boss("Boss", 1);

//     // const char* names[] = {
//     //     "shrubbery creation",
//     //     "robotomy request",
//     //     "presidential pardon",
//     //     "unknown form"
//     // };

//     // const char* targets[] = {
//     //     "home",
//     //     "Bender",
//     //     "Marvin",
//     //     "Nobody"
//     // };

//     // for (int i = 0; i < 4; ++i)
//     // {
//     //     std::cout << "\n-- Requesting form: " << names[i] << " (target: " << targets[i] << ") --" << std::endl;
//     //     AForm* form = someRandomIntern.makeForm(names[i], targets[i]);
//     //     if (!form)
//     //     {
//     //         std::cout << "Intern failed to create form: " << names[i] << std::endl;
//     //         continue;
//     //     }

//     //     std::cout << *form << std::endl;

//     //     try
//     //     {
//     //         boss.signForm(*form);
//     //     }
//     //     catch (std::exception& e)
//     //     {
//     //         std::cout << "Sign failed: " << e.what() << std::endl;
//     //     }

//     //     try
//     //     {
//     //         boss.executeForm(*form);
//     //     }
//     //     catch (std::exception& e)
//     //     {
//     //         std::cout << "Execute failed: " << e.what() << std::endl;
//     //     }

//     //     delete form;
//     // }

//     return (0);
// }


#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *shrub_form = NULL;
    AForm *robot_form = NULL;
    AForm *president_form = NULL;
    AForm *invalid_form = NULL;

	try
	{
		std::cout << YELLOW << "=========== shrubbery creation test ===========" << DEFAULT << std::endl;
		shrub_form = someRandomIntern.makeForm("shrubbery creation form", "Home");
		std::cout << *shrub_form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Intern failed to create shrubbery form: " << e.what() << std::endl;
	}
	try
	{
		std::cout << YELLOW << "=========== robotomy request test ===========" << DEFAULT << std::endl;
		robot_form = someRandomIntern.makeForm("robotomy request form", "Bender");
		std::cout << *robot_form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Intern failed to create robotomy form: " << e.what() << std::endl;
	}
	try
	{
		std::cout << YELLOW << "=========== presidential pardon test ===========" << DEFAULT << std::endl;
		president_form = someRandomIntern.makeForm("presidential pardon form", "Marvin");
		std::cout << *president_form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Intern failed to create presidential form: " << e.what() << std::endl;
	}
	try
	{
		std::cout << YELLOW << "=========== invalid form test ===========" << DEFAULT << std::endl;
		invalid_form = someRandomIntern.makeForm("invalid form", "Nobody");
		std::cout << *invalid_form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Intern failed to create invalid form: " << e.what() << std::endl;
	}

	Bureaucrat boss("Boss", 1);
	try
	{
		if (shrub_form)
		{
			boss.signForm(*shrub_form);
			shrub_form->execute(boss);
		}
		if (robot_form)
		{
			boss.signForm(*robot_form);
			for (int i = 0; i < 10; ++i)
			{
				try
				{
					robot_form->execute(boss); // random success/failure
				}
				catch (std::exception &e)
				{
					std::cout << "Execution attempt " << (i + 1) << " failed: " << e.what() << std::endl;
				}
			}
		}
		if (president_form)
		{
			boss.signForm(*president_form);
			president_form->execute(boss);
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error during signing/execution: " << e.what() << std::endl;
	}

	std::cout << "==============================================================" << std::endl;


    delete shrub_form;
    delete robot_form;
    delete president_form;
    delete invalid_form;

    return (0);
}