
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

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << YELLOW << "\n===== Test valid Form construction and output: =====\n" << DEFAULT << std::endl;
    try
    {
        Form leaveForm("Leave Request", 50, 30);
        std::cout << leaveForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n===== Test Form construction with grade too high: =====\n" << DEFAULT << std::endl;
    try
    {
        Form invalidFormHigh("Invalid High", 0, 30);
        std::cout << invalidFormHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n===== Test Form construction with grade too low: =====\n" << DEFAULT << std::endl;
    try
    {
        Form invalidFormLow("Invalid Low", 151, 30);
        std::cout << invalidFormLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n===== Test signing with sufficient grade: =====\n" << DEFAULT << std::endl;
    try
    {
        Bureaucrat robin("Robin", 10);
        std::cout << robin << std::endl;
        Form permit("Permit", 20, 10);
        std::cout << permit << std::endl;

        robin.signForm(permit);
        std::cout << permit << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n===== Test signing with insufficient grade: =====\n" << DEFAULT << std::endl;
    try
    {
        Bureaucrat chopper("Chopper", 100);
        std::cout << chopper << std::endl;
        Form secret("Secret Doc", 50, 10);
        std::cout << secret << std::endl;

        chopper.signForm(secret);
        std::cout << secret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n===== Test signing an already signed form: =====\n" << DEFAULT << std::endl;
    try
    {
        Bureaucrat franky("Franky", 1);
        std::cout << franky << std::endl;
        Form blueprint("Blueprint", 10, 5);
        std::cout << blueprint << std::endl;

        franky.signForm(blueprint);
        franky.signForm(blueprint); // Should not throw, but should indicate already signed
        std::cout << blueprint << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}
