#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor is called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << "PresidentialPardonForm copy constructor is called" << std::endl;
	this->_target = other._target;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor is called for " << this->getName() << std::endl;
}

// Getters and Setters
std::string &PresidentialPardonForm::getTarget()
{
	return (this->_target);
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

// Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm copy assignment is called for PresidentialPardonForm " << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
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
