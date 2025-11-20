#pragma once

#include "AForm.hpp"

class	AForm;

class	Intern
{
	public:

		// Constructors
		Intern(const Intern &form);

		// Operators
		Intern &operator=(const Intern &form);

		// Destructor
		~Intern();

		// Member functions
		AForm&	makeForm(std::string const &form_name, std::string const &form_target);

};

std::ostream& operator<<(std::ostream& os, Intern &form);
