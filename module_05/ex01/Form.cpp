
#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form(const std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	std::cout << "Form constructor is called for " << name << std::endl;
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

Form::Form(const Form& other) : _name(other._name), _signed_status(other._signed_status),  _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
	std::cout << "Form copy constructor is called" << std::endl;
	*this = other;
}

// Destructor
Form::~Form()
{
	std::cout << "Form destructor is called for " << this->_name << std::endl;
}

// Getters and Setters
std::string Form::getName() const
{
	return (_name);
}

bool Form::getSignedStatus() const
{
	return (_signed_status);
}

int Form::getGradeToSign() const
{
	return (_grade_to_sign);
}

int Form::getGradeToExecute() const
{
	return (_grade_to_execute);
}

// Member functions
void Form::beSigned(Bureaucrat &b_crat)
{
	if (b_crat.getGrade() <= this->_grade_to_sign)
	{
		this->_signed_status = true;
	}
	else
		throw GradeTooLowException();
}

// Operators
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		// _name and grades are const, so we can't assign to them here
		_signed_status = other._signed_status;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << BLUE << "-------- Form Info: --------\n" \
	<< "Form name: " << form.getName() << "\n" << "Grade to sign: " << form.getGradeToSign() << "\n" << "Grade to execute: " << form.getGradeToExecute() << "\n" << "Form Signed: " << form.getSignedStatus()\
	<< "\n----------------------------" << DEFAULT;
	return (os);
}
