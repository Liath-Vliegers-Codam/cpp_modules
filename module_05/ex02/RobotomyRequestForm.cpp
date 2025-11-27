#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor is called" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form)
{
	std::cout << "RobotomyRequestForm copy constructor is called" << std::endl;
	this->_target = form._target;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor is called for " << this->getName() << std::endl;
}

// Getters and Setters
std::string &RobotomyRequestForm::getTarget()
{
	return (this->_target);
}

// Member functions
bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static bool seeded = false;
    if (!seeded)
    {
		std::srand(static_cast<unsigned int>(std::time(NULL))); // Seeding initializes the pseudo-random number generator (PRNG) so it produces a different sequence each run. 
        seeded = true;
    }

	if (getSignedStatus() == false)
		throw FormIsNotSigned();
	if (executor.getGrade() >= getGradeToExecute())
		throw ExecutorGradeTooLow();
	
	std::cout << "DDRRRRRRRRRRRRRR DRRRRR DDDDRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	
	int random_number = rand() % 2; // generate 0 or 1
	if (random_number == 1)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		throw RobotomyRequestError();

	return (true);
}

// Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	std::cout << "RobotomyRequestForm copy assignment is called for RobotomyRequestForm " << std::endl;
	if (this != &form)
	{
		AForm::operator=(form);
		this->_target = form._target;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &os, RobotomyRequestForm &form)
{
	os << BLUE << "-------- Form Info: --------\n" \
	<< "Form name: " << form.getName() << "\n" \
	<< "Grade to sign: " << form.getGradeToSign() << "\n" \
	<< "Grade to execute: " << form.getGradeToExecute() << "\n" \
	<< "Form signed: " << form.getSignedStatus() << "\n" \
	<< "Form target: " << form.getTarget() << "\n" \
	<< "----------------------------" << DEFAULT;
	return (os);
}
