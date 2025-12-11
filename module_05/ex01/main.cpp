
/*
Exercise 01:			Form up, maggots!
Turn-in directory:		ex01/
Files to turn in:		Files from the previous exercise + Form.{h, hpp}, Form.cpp
Forbidden functions:	None

Now that you have bureaucrats, let’s give them something to do. 
What better activity could there be than filling out a stack of forms?

Let’s create a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it is not).
• A constant grade required to sign it.
• A constant grade required to execute it.

All these attributes are private, not protected.

The grades of the Form follow the same rules as those of the Bureaucrat.

Thus, the following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.

As before, write getters for all attributes and overload the insertion («) operator to print all the form’s information.

Also, add a beSigned() member function to the Form that takes a Bureaucrat as a parameter. 
It changes the form’s status to signed if the bureaucrat’s grade is high enough (greater than or equal to the required one). 

Remember, grade 1 is higher than grade 2.

If the grade is too low, throw a Form::GradeTooLowException.

Then, modify the signForm() member function in the Bureaucrat class. 
This function must call Form::beSigned() to attempt to sign the form.

If the form is signed successfully, it will print something like:
<bureaucrat> signed <form>

Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.

Implement and submit some tests to ensure everything works as expected.
*/

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << YELLOW << "\n------------ Test valid form construction and output: ------------\n" << DEFAULT << std::endl;
    try
    {
        Form validForm("Valid Form", 50, 30);
        std::cout << validForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n------------ Test invalid form construction with grade too high: ------------\n" << DEFAULT << std::endl;
    try
    {
        Form invalidFormHigh("Invalid Form Grade Too High", 0, 30);
        std::cout << invalidFormHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n------------ Test invalid form construction with grade too low: ------------\n" << DEFAULT << std::endl;
    try
    {
        Form invalidFormLow("Invalid Form Grade Too Low", 151, 30);
        std::cout << invalidFormLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n------------ Test signing with sufficient grade: ------------\n" << DEFAULT << std::endl;
    try
    {
        Bureaucrat robin("Robin", 10);
        std::cout << robin << std::endl;
        Form poneglyph("Road Poneglyph", 20, 10);
        std::cout << poneglyph << std::endl;

        robin.signForm(poneglyph);
        std::cout << poneglyph << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n------------ Test signing with insufficient grade: ------------\n" << DEFAULT << std::endl;
    try
    {
        Bureaucrat chopper("Chopper", 100);
        std::cout << chopper << std::endl;
        Form doctors_note("Doctors Note", 50, 10);
        std::cout << doctors_note << std::endl;

        chopper.signForm(doctors_note);
        std::cout << doctors_note << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n------------ Test signing an already signed form: ------------\n" << DEFAULT << std::endl;
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
