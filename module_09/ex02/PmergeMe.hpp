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

struct PairUnit
{
    int big;
    int small;
    size_t id;

    PairUnit() = default;
    PairUnit(int b, int s, size_t i) : big(b), small(s), id(i) {}
};

template <typename T>
class PmergeMe
{
	private:
		std::chrono::duration<double, std::micro> m_vector_sorting_time;
		std::chrono::duration<double, std::micro> m_deque_sorting_time;

		size_t m_elements;
		size_t m_comparisons;

		std::vector<T> m_unsorted_vec;
		std::vector<T> m_sorted_vec;
		
		std::deque<T> m_unsorted_deq;
		std::deque<T> m_sorted_deq;

	public:
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
		std::chrono::duration<double> get_vector_sorting_time(void) const;
		std::chrono::duration<double> get_deque_sorting_time(void) const;

		size_t get_elements(void) const;
		size_t get_comparisons(void) const;

		std::vector<T> get_unsorted_vec(void) const;
		std::vector<T> get_sorted_vec(void) const;
		
		std::deque<T> get_unsorted_deq(void) const;
		std::deque<T> get_sorted_deq(void) const;

		// Member functions
		template <typename Container>
		void print_container(const Container &cont);

		template <typename Container>
		typename Container::iterator binary_search(Container& cont, int value);
		
		std::vector<size_t> jacobsthal(size_t n);

		template <typename BigContainer, typename SmallContainer>
		void insert_small_numbers(BigContainer& big_chain, SmallContainer& small_chain);

		template <typename Container>
		void merge(Container& cont, const Container& left, const Container& right);
		
		template <typename Container>
		void merge_sort(Container& cont);
		
		template <typename PairContainer, typename BigContainer, typename SmallContainer>
		void split_pairs(const PairContainer& pairs, BigContainer& big_chain, SmallContainer& small_chain);
	
		template <typename InputContainer, typename PairContainer>
		int create_pairs(const InputContainer& input, PairContainer& pairs);
		
		void sort_with_vector();
		
		void sort_with_deque();
		
		void sort(void);
};

template <typename T>
std::ostream& operator<<(std::ostream &output_stream, const PmergeMe<T>& src);

#include "PmergeMe.tpp"