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
	Informs that <target> has been presidental_formed by Zaphod Beeblebrox.
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


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << YELLOW << "\n------------ ShrubberyCreationForm tests ------------\n" << DEFAULT << std::endl;
	try
	{
		ShrubberyCreationForm scrubbery_form("home");
		std::cout << scrubbery_form << std::endl;

		Bureaucrat robin("Robin", 140);

		std::cout << robin << std::endl;

		robin.signForm(scrubbery_form);

		try
		{
			scrubbery_form.execute(robin);
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by Robin failed: " << e.what() << std::endl;
		}

		Bureaucrat zorro("Zorro", 136);
		std::cout << zorro << std::endl;

		try
		{
			scrubbery_form.execute(zorro);
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by Zorro failed: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n------------ RobotomyRequestForm tests ------------\n" << DEFAULT << std::endl;
	try
	{
		RobotomyRequestForm robotomy_form("target_bot");
		std::cout << robotomy_form << std::endl;

		Bureaucrat chopper("Chopper", 100);
		std::cout << chopper << std::endl;
		chopper.signForm(robotomy_form); // expected to fail (sign grade 72)

		Bureaucrat franky("Franky", 50);
		std::cout << franky << std::endl;
		franky.signForm(robotomy_form); // should succeed (50 <= 72)

		try
		{
			robotomy_form.execute(franky); // expected to fail (exec grade 45)
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by Franky failed: " << e.what() << std::endl;
		}

		Bureaucrat nami("Nami", 40);
		std::cout << nami << std::endl;
		for (int i = 0; i < 20; ++i)
		{
			try
			{
				robotomy_form.execute(nami); // random success/failure
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

	std::cout << YELLOW << "\n------------ PresidentialPardonForm tests ------------\n" << DEFAULT << std::endl;
	try
	{
		PresidentialPardonForm presidental_form("Marvin the Paranoid Android");
		std::cout << presidental_form << std::endl;

		Bureaucrat sanji("Sanji", 25);
		std::cout << sanji << std::endl;
		sanji.signForm(presidental_form); // should succeed (sign grade 25)

		try
		{
			presidental_form.execute(sanji); // expected to fail (exec grade 5)
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by Sanji failed: " << e.what() << std::endl;
		}

		Bureaucrat luffy("Luffy", 1);
		std::cout << luffy << std::endl;
		try
		{
			presidental_form.execute(luffy); // should succeed
		}
		catch (std::exception &e)
		{
			std::cout << "Execution by Luffy failed: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Presidential tests exception: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n------------ Unsigned form execution test ------------\n" << DEFAULT << std::endl;
	try
	{
		ShrubberyCreationForm unsigned_form("home");
		std::cout << unsigned_form << std::endl;

		Bureaucrat ussop("Ussop", 1);
		try
		{
			unsigned_form.execute(ussop); // should report that form is not signed
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
