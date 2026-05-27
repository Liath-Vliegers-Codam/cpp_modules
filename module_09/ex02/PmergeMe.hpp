#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
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


		double m_starting_time;
		double m_vector_sorting_time;
		double m_deque_sorting_time;

		size_t m_vector_comparisons;
		size_t m_deque_comparisons;

	public:
		std::vector<T> m_unsorted_vec;	// MOVE BACK TO PRIVATE (maybe? -> we need to make a getter)
		std::vector<T> m_sorted_vec;	// MOVE BACK TO PRIVATE (maybe? -> we need to make a getter)
    	
		std::deque<T> m_unsorted_deq;	// MOVE BACK TO PRIVATE (maybe? -> we need to make a getter)
    	std::deque<T> m_sorted_deq;		// MOVE BACK TO PRIVATE (maybe? -> we need to make a getter)

		
		// Constructors
		PmergeMe(void)
		{
			std::cout << "PmergeMe default constructor is called" << std::endl;
		}

		template <typename Container>
		PmergeMe(const Container &input_container)
		{
			for (typename Container::const_iterator it = input_container.begin(); it != input_container.end(); it++)
			{
				m_unsorted_vec.push_back(*it);
				m_unsorted_deq.push_back(*it);
			}
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
std::ostream& operator<<(std::ostream &output_stream, const PmergeMe<T>& src)
{
	output_stream << "*PmergeMe Class info here*" << std::endl;
	return (output_stream);
}
