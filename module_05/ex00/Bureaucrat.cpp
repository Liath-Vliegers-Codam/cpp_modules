#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
	{
		// std::cout << GradeTooHighException() << std::endl;
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		// std::cout << GradeTooLowException() << std::endl;
		throw GradeTooLowException();
	}	
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
	return (*this);
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
	if (this->_grade == 1)
		throw GradeTooLowException();
	else
		this->_grade--;
	
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooHighException();
	else
		this->_grade++;
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}


const char* GradeTooHighException::what() const noexcept
{
	return ("maximum grade has been reached.");
}

const char* GradeTooLowException::what() const noexcept
{
	return ("minimum grade has been reached.");
}