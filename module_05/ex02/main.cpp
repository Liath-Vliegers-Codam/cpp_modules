
/*
Exercise 02 : No, you need form 28B, not 28C...
Turn-in directory: ex02/
Files to turn in:		Makefile, main.cpp, 
						Bureaucrat.[{h, hpp},cpp], 
						AForm.[{h, hpp},cpp], 
						ShrubberyCreationForm.[{h, hpp},cpp], 
						RobotomyRequestForm.[{h, hpp},cpp], 
						PresidentialPardonForm.[{h, hpp},cpp]
Forbidden functions:	None

Now that you have basic forms, it’s time to create a few more that actually do something.

In all cases, the base class Form must be an abstract class and should therefore be renamed AForm. 
Keep in mind that the form’s attributes need to remain private and that they belong to the base class.

Add the following concrete classes:
• ShrubberyCreationForm: Required grades: sign 145, exec 137
	Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
• RobotomyRequestForm: Required grades: sign 72, exec 45
	Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. 
	Otherwise, it informs that the robotomy failed.
• PresidentialPardonForm: Required grades: sign 25, exec 5
	Informs that <target> has been pardoned by Zaphod Beeblebrox.
All of them take only one parameter in their constructor: the target of the form. 
For example, "home" if you want to plant shrubbery at home.

Now, add the execute(Bureaucrat const & executor) const member function to the base form 
and implement a function to execute the form’s action in the concrete classes.

You must check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. 
Otherwise, throw an appropriate exception.

Whether you check the requirements in every concrete class or in the base class 
(and then call another function to execute the form) is up to you. However, one way is more elegant than the other.

Lastly, add the executeForm(AForm const & form) const member function to the Bureaucrat class. 
It must attempt to execute the form. If successful, print something like:
<bureaucrat> executed <form>
If not, print an explicit error message.

Implement and submit some tests to ensure everything works as expected.
*/

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{

	std::cout << YELLOW << "\n===== ShrubberyCreationForm tests =====\n" << DEFAULT << std::endl;
	try
	{
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;

		Bureaucrat alice("Alice", 140);

		std::cout << alice << std::endl;

		alice.signForm(shrub);

		try
		{
			shrub.execute(alice);
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by Alice failed: " << e.what() << std::endl;
		}

		Bureaucrat bob("Bob", 136);
		std::cout << bob << std::endl;

		try
		{
			shrub.execute(bob);
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by Bob failed: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n===== RobotomyRequestForm tests =====\n" << DEFAULT << std::endl;
	try
	{
		RobotomyRequestForm robo("target_bot");
		std::cout << robo << std::endl;

		Bureaucrat chopper("Chopper", 100);
		std::cout << chopper << std::endl;
		chopper.signForm(robo); // expected to fail (sign grade 72)

		Bureaucrat drillMaster("DrillMaster", 50);
		std::cout << drillMaster << std::endl;
		drillMaster.signForm(robo); // should succeed (50 <= 72)

		try
		{
			robo.execute(drillMaster); // expected to fail (exec grade 45)
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by DrillMaster failed: " << e.what() << std::endl;
		}

		Bureaucrat execGuy("ExecGuy", 40);
		std::cout << execGuy << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			try
			{
				robo.execute(execGuy); // random success/failure
			}
			catch (std::exception &e)
			{
				std::cout << "Execution attempt " << (i + 1) << " failed: " << e.what() << std::endl;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Robotomy tests exception: " << e.what() << std::endl;
	}


	std::cout << YELLOW << "\n===== PresidentialPardonForm tests =====\n" << DEFAULT << std::endl;
	try
	{
		PresidentialPardonForm pardon("Marvin");
		std::cout << pardon << std::endl;


		Bureaucrat clerk("Clerk", 25);
		std::cout << clerk << std::endl;
		clerk.signForm(pardon); // should succeed (sign grade 25)

		try
		{
			pardon.execute(clerk); // expected to fail (exec grade 5)
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by Clerk failed: " << e.what() << std::endl;
		}

		Bureaucrat president("President", 1);
		std::cout << president << std::endl;
		try
		{
			pardon.execute(president); // should succeed
		}
				catch (std::exception &e)
		{
			std::cout << "Execution by President failed: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Presidential tests exception: " << e.what() << std::endl;
	}


	std::cout << YELLOW << "\n===== Unsigned form execution test =====\n" << DEFAULT << std::endl;
	try
	{
		ShrubberyCreationForm unsignedForm("garden");
		std::cout << unsignedForm << std::endl;

		Bureaucrat smallGuy("SmallGuy", 1);
		try
		{
			unsignedForm.execute(smallGuy); // should report that form is not signed
		}
		catch (std::exception &e)
		{
			std::cout << "Execution failed: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Unsigned form test exception: " << e.what() << std::endl;
	}

	return (0);
}
