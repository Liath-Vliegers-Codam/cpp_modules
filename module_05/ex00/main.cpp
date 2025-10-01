
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

#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150


class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);


		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		std::string GradeTooHighException();
		std::string GradeTooLowException();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		std::cout << GradeTooHighException() << std::endl;
	if (grade > 150)
		std::cout << GradeTooLowException() << std::endl;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this != &other)
	{
		// _name is const, so we can't assign to it here
		_grade = other._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooHighException();
	else
		this->_grade++;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooLowException();
	else
		this->_grade--;
}

std::string Bureaucrat::GradeTooHighException()
{
	return ("MAX Grade");
}

std::string Bureaucrat::GradeTooLowException()
{
	return ("MIN Grade");
}



int	main(void)
{
	try
	{
		Bureaucrat john("John", 10);
		Bureaucrat bert("Bert", 0);
		Bureaucrat ernie("Ernie", 1000);

		std::cout << john << std::endl;
		std::cout << bert << std::endl;
		std::cout << ernie << std::endl;

		john.incrementGrade();
		std::cout << john << std::endl;

		john.decrementGrade();
		std::cout << john << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

