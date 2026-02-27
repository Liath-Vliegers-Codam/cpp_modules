/*
	PresidentialPardonForm: Required grades: sign 25, exec 5
	Informs that <target> has been pardoned by Zaphod Beeblebrox.
	All of them take only one parameter in their constructor: the target of the form. 
	For example, "home" if you want to plant shrubbery at home.
*/

#pragma once
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		// Constructors
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &form);

		// Destructors
		virtual ~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm &operator=(const PresidentialPardonForm &form);

		// Member functions
		void execute(Bureaucrat const & executor) const;

		// Getters and Setters
		std::string &getTarget();
};

std::ostream& operator<<(std::ostream &os, PresidentialPardonForm &form);
