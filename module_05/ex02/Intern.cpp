#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"


Intern::Intern(const Intern &form)
{
	*this = form;
}

Intern&	Intern::operator=(const Intern &form)
{
	if (sizeof(form))
		std::cout << "Intern copy assignment is called" << std::endl;
	return (*this);
}

Intern::~Intern()
{

}


static	AForm* createShrubberyCreatorForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static	AForm* createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static	AForm* createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm &Intern::makeForm(std::string const &form_name, std::string const &form_target)
{
	std::string form_names[3] = {"shrubbery creation form", "robotomy request form", "presidential pardon form"};
	AForm* (*formConstructors[3])(std::string const &) = {createShrubberyCreatorForm, createRobotomyRequestForm, createPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (form_names[i] == form_name)
		{
			std::cout << "Intern created " << form_name << std::endl;
			return (*(formConstructors[i])(form_target));
		}
	}
	throw FormNotFound();
}

std::ostream& operator<<(std::ostream& os, Intern &form)
{
	if (sizeof(form))
		os << "This is an Intern, they can only make forms.";
	return (os);
}


