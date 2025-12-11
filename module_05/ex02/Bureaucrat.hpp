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

class AForm;

class Bureaucrat 
{
	private:
		const std::string _name;
		int _grade;

	public:
		// Constructors
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
	
		// Destructor	
		~Bureaucrat();

		// Operators
		Bureaucrat& operator=(const Bureaucrat& other);

		// Getters and Setters
		std::string getName() const;
		int getGrade() const;

		// Member functions
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& formToSign);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

// Exceptions
class GradeTooHighException : public std::exception
{
	const char* what() const noexcept override;
};

class GradeTooLowException : public std::exception
{
	const char* what() const noexcept override;
};