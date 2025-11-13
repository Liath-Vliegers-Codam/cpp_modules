#pragma once

#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150


class Bureaucrat 
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();



		// std::string GradeTooHighException();
		// std::string GradeTooLowException();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


class GradeTooHighException : public std::exception
{
		const char* what() const noexcept override;
};

class GradeTooLowException : public std::exception
{
		const char* what() const noexcept override;
};