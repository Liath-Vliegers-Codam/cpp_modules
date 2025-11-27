#pragma once

#include <iostream>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

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
