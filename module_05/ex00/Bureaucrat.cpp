#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < MAX_GRADE)
	{
		throw GradeTooHighException();
	}
	if (grade > MIN_GRADE)
	{
		throw GradeTooLowException();
	}	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	std::cout << "Bureaucrat copy constructor is called" << std::endl;
	*this = other;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor is called for " << this->_name << std::endl;
}

// Getters and Setters
std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

// Member functions
void Bureaucrat::incrementGrade()
{
	if (this->_grade == MAX_GRADE)
		throw GradeTooLowException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == MIN_GRADE)
		throw GradeTooHighException();
	else
		this->_grade++;
}

// Operators
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

// Exceptions
const char* GradeTooHighException::what() const noexcept
{
	return ("Grade is too high.");
}

const char* GradeTooLowException::what() const noexcept
{
	return ("Grade is too low.");
}
