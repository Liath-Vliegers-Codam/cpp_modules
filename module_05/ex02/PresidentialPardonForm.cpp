#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form)
{
	this->_target = form._target;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{

}

// Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		this->_target = form._target;
	}
	return (*this);
}

// Member functions
bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSignedStatus() == false)
		throw FormIsNotSigned();
	if (executor.getGrade() >= getGradeToExecute())
		throw ExecutorGradeTooLow();
	else
	{
		std::cout << "PresidentialPardonForm \"" << this->_target << "\" has been pardoned by Zaphod Beeblebrox" << std::endl; 
		return (true);
	}
	return (false);
}

// Getters and Setters
std::string &PresidentialPardonForm::getTarget()
{
	return (this->_target);
}

std::ostream& operator<<(std::ostream &os, PresidentialPardonForm &form)
{
	os << BLUE << "-------- Form Info: --------\n" \
	<< "Form name: " << form.getName() << "\n" \
	<< "Grade to sign: " << form.getGradeToSign() << "\n" \
	<< "Grade to execute: " << form.getGradeToExecute() << "\n" \
	<< "Form Signed: " << form.getSignedStatus() << "\n" \
	<< "Form target: " << form.getTarget() << "\n" \
	<< "----------------------------" << DEFAULT;
	return (os);
}
