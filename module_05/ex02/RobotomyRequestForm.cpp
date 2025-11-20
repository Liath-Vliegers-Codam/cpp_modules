#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form)
{
	this->_target = form._target;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{

}

// Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		this->_target = form._target;
	}
	return (*this);
}

// Getters and Setters
std::string &RobotomyRequestForm::getTarget()
{
	return (this->_target);
}

// Member functions
bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSignedStatus() == false)
		throw FormIsNotSigned();
	if (executor.getGrade() >= getGradeToExecute())
		throw ExecutorGradeTooLow();
	else
	{
		std::cout << "DDRRRRRRRRRRRRRR DRRRRR DDDDRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	
		int random_number = rand() % 2; // generate 0 or 1
		if (random_number == 1)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			throw RobotomyRequestError();
		return (true);
	}
	return (false);
}

std::ostream& operator<<(std::ostream &os, RobotomyRequestForm &form)
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
