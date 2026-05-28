#pragma once

#include "parser.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <sstream>
#include <chrono>
#include <ctime>
#include <thread>

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

	public:
	// MOVE BACK TO PRIVATE (maybe? -> we need to make getters)
		std::chrono::duration<double> m_vector_sorting_time;
		std::chrono::duration<double> m_deque_sorting_time;

		size_t m_elements;

		size_t m_vector_comparisons;
		size_t m_deque_comparisons;

		std::vector<T> m_unsorted_vec;
		std::vector<T> m_sorted_vec;
    	
		std::deque<T> m_unsorted_deq;
    	std::deque<T> m_sorted_deq;

		// Constructors
		PmergeMe(void);

		template <typename Container>
		PmergeMe(const Container &input_container);

		PmergeMe(const PmergeMe& other);

		// Destructor
		~PmergeMe(void);

		// Operators
		PmergeMe &operator=(const PmergeMe& other);


		// Getters and Setters


		// Member functions
				
		template <typename InputContainer, typename OutputContainer>
		int parse_pairs(InputContainer unsorted_array, OutputContainer &pair_array);

		template <typename PairContainer>
		void big_sort(PairContainer it_begin, PairContainer it_end);

		template <typename PairContainer, typename SortedContainer>
		void small_sort(PairContainer pairs_array, SortedContainer sorted_array, int struggler);


		void sort();
		void sort_with_vector(void);
		void sort_with_deque(void);
};

// template <typename T>
// std::ostream& operator<<(std::ostream &output_stream, const PmergeMe<T>& src);


#include "PmergeMe.tpp"