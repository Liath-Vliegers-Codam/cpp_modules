
#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed_status;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

	protected:
		// contructors
		AForm(const std::string name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm &other);


	public:
		virtual ~AForm();
		
		AForm& operator=(const AForm &other);

		std::string getName() const;
		bool getSignedStatus() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat &b_crat);
		virtual bool execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator<<(std::ostream &os, const AForm &form);

class AFormException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "AForm Exception occurred!";
		}
};

class FormIsNotSigned : public AFormException
{
	public:
		const char* what() const throw()
		{
			return "Form is not signed!";
		}
};

class ExecutorGradeTooLow : public AFormException
{
	public:
		const char* what() const throw()
		{
			return "Executor's grade is too low to execute the form!";
		}
};



// REMOVE!!!! in ex02 only for ex03::

class FormNotFound : public AFormException
{
public:
    const char* what() const throw()
    {
        return "Form was not found!";
    }
};
