#include "Form.hpp"
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << GREEN << "----- Bureaucrat Info: -----\n" \
	<< "Bureaucrat name: " << bureaucrat.getName() << "\n" << "Bureaucrat grade: " << bureaucrat.getGrade() \
	<< "\n----------------------------" << DEFAULT;
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

void Bureaucrat::signForm(Form& formToSign)
{
	
	if (formToSign.getSignedStatus() == true)
		std::cout << this->_name << " could not sign the form "<< formToSign.getName() << " because it is already signed." << std::endl;
	else
	{
		try
		{
			formToSign.beSigned(*this);
			std::cout << "The form "<< formToSign.getName() << " has been successfully signed by " << this->_name << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << this->_name << " could not sign the form "<< formToSign.getName() << " because ";
			std::cerr << e.what() << std::endl;
		}
	} 
}

const char* GradeTooHighException::what() const noexcept
{
	return ("maximum grade has been reached.");
}

const char* GradeTooLowException::what() const noexcept
{
	return ("minimum grade has been reached.");
}
