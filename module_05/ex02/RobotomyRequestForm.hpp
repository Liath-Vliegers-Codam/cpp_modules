/*
	RobotomyRequestForm: Required grades: sign 72, exec 45
	Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. 
	Otherwise, it informs that the robotomy failed.
*/

#pragma once
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		// Constructors
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &form);

		// Destructors
		virtual ~RobotomyRequestForm();

		// Operators
		RobotomyRequestForm &operator=(const RobotomyRequestForm &form);

		// Getters and Setters
		std::string &getTarget();

		// Member functions
		bool execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &os, RobotomyRequestForm &form);

class RobotomyRequestException : public AFormException
{
	public:
		const char* what() const throw()
		{
			return "RobotomyRequestForm Exception occurred!";
		}
};

// Specific exception for file error in RobotomyRequestForm
class RobotomyRequestError : public RobotomyRequestException
{
	public:
		const char* what() const throw()
		{
			return  "Robotomy failed!";
		}
};

