
/*
	Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
	Exercise : 00 Mommy, when I grow up, I want to be a bureaucrat!
	Turn-in directory: 		ex00/
	Files to turn in: 		Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp
	Forbidden functions: 	None
	Please note that exception classes do not have to be designed in Orthodox Canonical Form. 
	However, every other class must follow it.
	Let’s design an artificial nightmare of offices, corridors, forms, and waiting queues.
	First, start with the smallest cog in this vast bureaucratic machine: the Bureaucrat.
	A Bureaucrat must have:
	• A constant name.
	• A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
	Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:
	either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

	You will provide getters for both attributes: getName() and getGrade(). 
	You must also implement two member functions to increment or decrement the bureaucrat’s grade.
	If the grade goes out of range, both functions must throw the same exceptions as the constructor.
	Remember, since grade 1 is the highest and 150 the lowest,
	incrementing a grade 3 should result in a grade 2 for the bureaucrat.
	The thrown exceptions must be catchable using try and catch blocks:

	try
	{
		// do some stuff with bureaucrats
	}
	catch (std::exception & e)
	{
		// handle exception
	}

	You must implement an overload of the insertion («) operator to print output in the
	following format (without the angle brackets):
	<name>, bureaucrat grade <grade>.
	As usual, submit some tests to prove that everything works as expected.
*/

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << YELLOW << "------------ Test valid construction and output ------------" << DEFAULT << std::endl;
	try
	{
		Bureaucrat luffy("Luffy", 10);
		std::cout << luffy << std::endl;

		luffy.incrementGrade();
		std::cout << luffy << std::endl;

		luffy.decrementGrade();
		std::cout << luffy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "------------ Test construction with grade too high ------------" << DEFAULT << std::endl;
	try
	{
		Bureaucrat zorro("Zorro", 0);
		std::cout << zorro << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "------------ Test construction with grade too low ------------" << DEFAULT << std::endl;
	try
	{
		Bureaucrat usopp("Usopp", 1000);
		std::cout << usopp << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "------------ Test incrementing at highest grade ------------" << DEFAULT << std::endl;
	try
	{
		Bureaucrat nami("Nami", 1);
		std::cout << nami << std::endl;
		nami.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "------------ Test decrementing at lowest grade ------------" << DEFAULT << std::endl;
	try
	{
		Bureaucrat sanji("Sanji", 150);
		std::cout << sanji << std::endl;
		sanji.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}	
	return (0);
}
