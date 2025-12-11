/*
	ShrubberyCreationForm: Required grades: sign 145, exec 137
	Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
*/

#pragma once
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		// Constructors
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &form);

		// Destructors
		virtual ~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
	
		// Getters and Setters
		std::string &getTarget();
	
		// Member functions
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &os, ShrubberyCreationForm &form);

// Exceptions
class ShrubberyCreationException : public AFormException
{
	public:
		const char* what() const throw()
		{
			return ("ShrubberyCreationForm Exception occurred!");
		}
};

class ShrubberyFileError : public ShrubberyCreationException
{
	public:
		const char* what() const throw()
		{
			return ("Error creating the shrubbery file!");
		}
};
