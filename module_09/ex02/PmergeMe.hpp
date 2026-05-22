#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"


template <typename T>
class PmergeMe
{
	private:
		T m_unsorted_container;
		T m_sorted_container;

	public:
		// Constructors
		PmergeMe(void) 
		{
    		std::cout << "PmergeMe default constructor is called" << std::endl;
		}

		PmergeMe(T unsorted_container) : m_unsorted_container(unsorted_container)
		{
			std::cout << "PmergeMe parameterized constructor is called" << std::endl;
		}

		PmergeMe(const PmergeMe& other)
		{
			*this = other;
			std::cout << "PmergeMe copy constructor is called" << std::endl;
		}

		// Destructor
		~PmergeMe(void)
		{
			std::cout << "PmergeMe destructor is called" << std::endl;
		}

		// Operators
		PmergeMe &operator=(const PmergeMe& other)
		{
			if (this != &other)
			{
				// copy data members here
				std::cout << "PmergeMe copy assignment is called" << std::endl;
			}
			return (*this);
		}

		// Getters and Setters

		// Member functions
};

template <typename T>
std::ostream& operator<<(std::ostream &output_stream, PmergeMe<T>& src)
{
	(void)src;
	output_stream << "*PmergeMe Class info here*" << std::endl;
	return (output_stream);
};
