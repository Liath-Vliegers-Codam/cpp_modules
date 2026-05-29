

#include "parser.hpp"
#include "PmergeMe.hpp"

// Constructors
template <typename T>
PmergeMe<T>::PmergeMe(void)
{
	std::cout << BLUE << "PmergeMe default constructor is called" << DEFAULT << std::endl;
}

template <typename T>
template <typename Container>
PmergeMe<T>::PmergeMe(const Container &input_container)
{
	m_elements = 0;
	m_vector_comparisons = 0;
	m_deque_comparisons = 0;

	for (typename Container::const_iterator it = input_container.begin(); it != input_container.end(); it++)
	{
		m_unsorted_vec.push_back(*it);
		m_unsorted_deq.push_back(*it);
		m_elements++;
	}
	std::cout << BLUE << "PmergeMe parameterized constructor is called" << DEFAULT << std::endl;
	print_container(m_unsorted_deq, "DEQUE: ");
	print_container(m_unsorted_vec, "VECTOR: ");
	std::cout << YELLOW << "Elements: " << m_elements << DEFAULT << std::endl;

}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& other)
{
	*this = other;
	std::cout << BLUE << "PmergeMe copy constructor is called" << DEFAULT << std::endl;
}

// Destructor
template <typename T>
PmergeMe<T>::~PmergeMe(void)
{
	std::cout << BLUE << "PmergeMe destructor is called" << DEFAULT << std::endl;
}



// Getters and Setters


// Member functions


template <typename T>
template <typename InputContainer, typename OutputContainer>
int PmergeMe<T>::parse_pairs(InputContainer unsorted_array, OutputContainer &pairs_array)
{
	// this function takes the input, makes pairs with their neigbour, 
	// and puts the bigger number of the two in the first and the smaller one in small.
	auto array_it = unsorted_array.begin();

	for (auto pairs_it = pairs_array.begin(); pairs_it != pairs_array.end(); pairs_it++)
	{
		pairs_it->first = *array_it;
		array_it++;
		pairs_it->second = *array_it;

		if (pairs_it->first < pairs_it->second)
		{
			std::swap(pairs_it->first, pairs_it->second);
		}

		array_it++;
	}

	if (array_it != unsorted_array.end())
		return (*array_it);
	else
		return (-1);
}

template <typename PairContainer>
void print_big_numbers(PairContainer pairs_array)
{
	auto it = pairs_array.begin();

	std::cout << "BIG NUMBERS:" << std::endl;
	while (it != pairs_array.end())
	{
		std::cout << it->first << std::endl;
		it++;
	}
	std::cout << "==============" << std::endl;
}

template <typename PairContainer>
void print_small_numbers(PairContainer pairs_array)
{
	auto it = pairs_array.begin();

	std::cout << "SMALL NUMBERS:" << std::endl;
	while (it != pairs_array.end())
	{
		std::cout << it->second << std::endl;
		it++;
	}
	std::cout << "==============" << std::endl;
}


template <typename T>
template <typename PairContainerIT>
void PmergeMe<T>::big_sort(PairContainerIT it_begin, PairContainerIT it_end)
{
	std::cout << MAGENTA << "let the BIG sorting begin" << DEFAULT << std::endl;
	(void)it_begin;
	(void)it_end;
}

template <typename T>
template <typename PairContainer, typename SortedContainer>
void PmergeMe<T>::small_sort(PairContainer pairs_array, SortedContainer sorted_array, int struggler)
{
	std::cout << MAGENTA << "let the SMALL sorting begin" << DEFAULT << std::endl;
	(void)pairs_array;
	(void)sorted_array;
	(void)struggler;
}

template <typename T>
void PmergeMe<T>::sort_with_vector(void)
{
	std::cout << MAGENTA << "let the sorting with vector begin" << DEFAULT << std::endl;
	
	auto start_time = std::chrono::system_clock::now();

	int struggler;
	std::vector<std::pair<int, int>> pairs_vec;
	
	pairs_vec.resize(m_elements / 2);

	struggler = parse_pairs(m_unsorted_vec, pairs_vec);
	
	// ==== DEBUG ====
	print_big_numbers(pairs_vec);
	print_small_numbers(pairs_vec);
	std::cout << "struggler: " << struggler << std::endl;
	// ===============

	big_sort(pairs_vec.begin(), pairs_vec.end() - 1);
	small_sort(pairs_vec, m_sorted_vec, struggler);

    auto end_time = std::chrono::system_clock::now();

    m_vector_sorting_time = end_time - start_time;
}

// template <typename T>
// void PmergeMe<T>::sort_with_deque(void)
// {
// 	std::cout << MAGENTA << "let the sorting with deque begin" << DEFAULT << std::endl;
	
// 	auto start_time = std::chrono::system_clock::now();

// 	int struggler;
// 	std::vector<std::pair<int, int>> pairs_deq;
	
// 	pairs_deq.resize(m_elements / 2);

// 	struggler = parse_pairs(m_unsorted_deq, pairs_deq);

// 	// ==== DEBUG ====
// 	print_big_numbers(pairs_deq);
// 	print_small_numbers(pairs_deq);
// 	std::cout << "struggler: " << struggler << std::endl;
// 	// ===============

// 	big_sort(pairs_deq.begin(), pairs_deq.end() - 1);
// 	small_sort(pairs_deq, m_sorted_deq, struggler);

//     auto end_time = std::chrono::system_clock::now();

//     m_deque_sorting_time = end_time - start_time;
// }


template <typename T>
void PmergeMe<T>::sort(void)
{
	std::cout << MAGENTA << "let the sorting begin" << DEFAULT << std::endl;

    std::cout << "Before:\t"; 
	print_container(m_unsorted_vec, "");

    this->sort_with_vector();
    // this->sort_with_deque();

    std::cout << "After:\t";
	print_container(m_sorted_vec, "");

    std::cout << "Time to process a range of " << m_elements << " elements with std::vector : " << (m_vector_sorting_time / 1000) << " us\n";
    std::cout << "Time to process a range of " << m_elements << " elements with std::deque  : " << (m_deque_sorting_time / 1000) << " us\n";
}


// Operators
template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe<T>& other)
{
	if (this != &other)
	{
		// copy data members here
		std::cout << BLUE << "PmergeMe copy assignment is called" << DEFAULT << std::endl;
	}
	return (*this);
}


template <typename T>
std::ostream& operator<<(std::ostream &output_stream, const PmergeMe<T>& src)
{
	(void)src;
	
	output_stream << "*PmergeMe Class info here*" << std::endl;
	return (output_stream);
}
