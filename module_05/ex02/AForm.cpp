
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
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

AForm::~AForm()
{

}


AForm::AForm(const AForm& other) : _name(other._name), _signed_status(other._signed_status),  _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		// _name and grades are const, so we can't assign to them here
		_signed_status = other._signed_status;
	}
	return (*this);
}


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

void AForm::beSigned(Bureaucrat &b_crat)
{
	if (b_crat.getGrade() <= this->_grade_to_sign)
	{
		this->_signed_status = true;
		// std::cout << "Form " << this->_name << " is signed by " << b_crat.getName() << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << BLUE << "-------- AForm Info: --------\n" \
	<< "AForm name: " << form.getName() << "\n" << "Grade to sign: " << form.getGradeToSign() << "\n" << "Grade to execute: " << form.getGradeToExecute() << "\n" << "AForm Signed: " << form.getSignedStatus()\
	<< "\n----------------------------" << DEFAULT;
	return (os);
}
