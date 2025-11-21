
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm(const std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	std::cout << "AForm constructor is called for " << name << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
	{
		throw GradeTooHighException();
	}
	if (grade_to_sign > 150 || grade_to_execute > 150)
	{
		throw GradeTooLowException();
	}	
	this->_signed_status = false;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed_status(other._signed_status),  _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
	std::cout << "AForm copy constructor is called" << std::endl;
	*this = other;
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm destructor is called for " << this->_name << std::endl;
}

// Getters and Setters
std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSignedStatus() const
{
	return (this->_signed_status);
}

int AForm::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

// Member functions
void AForm::beSigned(Bureaucrat &b_crat)
{
	if (b_crat.getGrade() <= this->_grade_to_sign)
	{
		this->_signed_status = true;
	}
	else
		throw GradeTooLowException();
}

// Operators
AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignment is called for " << other._name << std::endl;
	if (this != &other)
	{
		// _name and grades are const, so we can't assign to them here
		_signed_status = other._signed_status;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << BLUE << "-------- AForm Info: --------\n" \
	<< "AForm name: " << form.getName() << "\n" << "Grade to sign: " << form.getGradeToSign() << "\n" << "Grade to execute: " << form.getGradeToExecute() << "\n" << "AForm Signed: " << form.getSignedStatus()\
	<< "\n----------------------------" << DEFAULT;
	return (os);
}
