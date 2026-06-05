#include "parser.hpp"
#include "PmergeMe.hpp"

// Constructors
template <typename T>
PmergeMe<T>::PmergeMe(void)
{
	// std::cout << BLUE << "PmergeMe default constructor is called" << DEFAULT << std::endl;
}

template <typename T>
template <typename Container>
PmergeMe<T>::PmergeMe(const Container &input_container)
{
	for (typename Container::const_iterator it = input_container.begin(); it != input_container.end(); it++)
	{
		m_unsorted_vec.push_back(*it);
		m_unsorted_deq.push_back(*it);
		m_elements++;
	}
	// std::cout << BLUE << "PmergeMe parameterized constructor is called" << DEFAULT << std::endl;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& other)
{
	*this = other;
	// std::cout << BLUE << "PmergeMe copy constructor is called" << DEFAULT << std::endl;
}

// Destructor
template <typename T>
PmergeMe<T>::~PmergeMe(void)
{
	// std::cout << BLUE << "PmergeMe destructor is called" << DEFAULT << std::endl;
}

// Getters and Setters
template <typename T>
std::chrono::duration<double> PmergeMe<T>::get_vector_sorting_time(void) const
{
	return (m_vector_sorting_time);
}

template <typename T>
std::chrono::duration<double> PmergeMe<T>::get_deque_sorting_time(void) const
{
	return (m_deque_sorting_time);
}

template <typename T>
size_t PmergeMe<T>::get_elements(void) const
{
	return (m_elements);
}

template <typename T>
size_t PmergeMe<T>::get_comparisons(void) const
{
	return (m_comparisons);
}

template <typename T>
std::vector<T> PmergeMe<T>::get_unsorted_vec(void) const
{
	return (m_unsorted_vec);
}

template <typename T>
std::vector<T> PmergeMe<T>::get_sorted_vec(void) const
{
	return (m_sorted_vec);
}

template <typename T>
std::deque<T> PmergeMe<T>::get_unsorted_deq(void) const
{
	return (m_unsorted_deq);
}

template <typename T>
std::deque<T> PmergeMe<T>::get_sorted_deq(void) const
{
	return (m_sorted_deq);
}

// Member functions
template <typename T>
template <typename InputContainer, typename OutputContainer>
int PmergeMe<T>::create_pairs(InputContainer unsorted_array, OutputContainer &pairs)
{
	typename InputContainer::const_iterator it = unsorted_array.begin();
	size_t id = 0;
	
	while (it != unsorted_array.end())
	{
		int first = *it;
		it++;

		if (it == unsorted_array.end())
			return (first); // struggler

		int second = *it;
		it++;

		if (first > second)  // comparison
			pairs.push_back(PairUnit{first, second, id});
		else
			pairs.push_back(PairUnit{second, first, id});
		
		m_comparisons++;
		id++;
	}
	return (-1);
}

template <typename T>
template <typename Container>
void PmergeMe<T>::sort_big_numbers(Container &pairs)
{
	if (pairs.size() < 2)
		return;

	Container sorted;
	sorted.push_back(pairs.front());

	typename Container::const_iterator it = pairs.begin();
	it++;

	for (; it != pairs.end(); it++)
	{
		size_t left = 0;
		size_t right = sorted.size();

		while (left < right)
		{
			size_t mid = left + (right - left) / 2;

			if (it->big < sorted[mid].big) // comparison
				right = mid;
			else
				left = mid + 1;

			m_comparisons++;
		}

		sorted.insert(sorted.begin() + left, *it);
	}

	pairs.swap(sorted);
}

template <typename T>
std::vector<size_t> PmergeMe<T>::fill_jacobsthal_sequence(size_t size)
{
	// Build the Jacobsthal sequence used to decide insertion order.
	// The sequence starts with 0 and 1, then each following number is found by adding the number before it to twice the number before that. The first Jacobsthal numbers are:
	// 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, … 
	std::vector<size_t> jacob_seq;
	jacob_seq.push_back(1);
	jacob_seq.push_back(1);

	while (jacob_seq.back() < size)
	{
		size_t i = jacob_seq.size();
		jacob_seq.push_back(jacob_seq[i - 1] + 2 * jacob_seq[i - 2]);
	}
	// std::cout << "jacob_seq:" << std::endl;
	// print_container(jacob_seq);
	return (jacob_seq);
}

template <typename T>
template <typename PairContainer, typename ResultContainer>
void PmergeMe<T>::insert_small_numbers(PairContainer& pairs, ResultContainer& result, int struggler)
{
	if (pairs.empty())
	{
		if (struggler != -1)
			m_sorted_vec.push_back(struggler);
		return;
	}

	std::vector<size_t> big_pos(pairs.size());
	for (size_t i = 0; i < pairs.size(); i++)
	{
		result.push_back(std::make_pair(pairs[i].big, pairs[i].id));
		big_pos[pairs[i].id] = i;
	}

	result.insert(result.begin(), std::make_pair(pairs[0].small, pairs[0].id));

	for (size_t i = 0; i < big_pos.size(); i++)
		big_pos[i]++;

	size_t processed = 1;

	std::vector<size_t> jacob_seq = fill_jacobsthal_sequence(pairs.size());

	for (size_t k = 0; k < jacob_seq.size(); k++)
	{
		size_t boundary = jacob_seq[k];

		if (boundary <= processed)
			continue;

		if (boundary > pairs.size())
			boundary = pairs.size();

		for (size_t idx = boundary; idx > processed; idx--)
		{
			size_t pair_index = idx - 1;
			size_t pair_id = pairs[pair_index].id;

			int small_val = pairs[pair_index].small;

			size_t upper = big_pos[pair_id];

			size_t left = 0;
			size_t right = upper;

			while (left < right) 
			{
				size_t mid = left + (right - left) / 2;
				
				if (right - left > 1) // only count if range > 1, in final iteration position is already determined.
					m_comparisons++;
					
				if (small_val < result[mid].first) // comparison
					right = mid;
				else
					left = mid + 1;
			}

			result.insert(result.begin() + left, std::make_pair(small_val, pair_id));

			for (size_t i = 0; i < big_pos.size(); i++)
			{
				if (big_pos[i] >= left)
					big_pos[i]++;
			}
		}

		processed = boundary;

		if (processed >= pairs.size())
			break;
	}

	if (struggler != -1)
	{
		size_t left = 0;
		size_t right = result.size();

		while (left < right) 
		{
			size_t mid = left + (right - left) / 2;
			
			if (right - left > 1) // only count if range > 1, in final iteration position is already determined.
				m_comparisons++;

			if (struggler < result[mid].first) // comparison
				right = mid;
			else
				left = mid + 1;	
		}
		result.insert(result.begin() + left, std::make_pair(struggler, static_cast<size_t>(-1)));
	}
}

template <typename T>
void PmergeMe<T>::sort_with_vector(void)
{
	m_comparisons = 0;
	auto start_time = std::chrono::system_clock::now();

	std::vector<PairUnit> pairs;

	int struggler = create_pairs(m_unsorted_vec, pairs);

	sort_big_numbers(pairs);

	std::vector<std::pair<int, size_t>> result;

	insert_small_numbers(pairs, result, struggler);

	m_sorted_vec.clear();
	
	for (size_t i = 0; i < result.size(); i++)
		m_sorted_vec.push_back(result[i].first);

	auto end_time = std::chrono::system_clock::now();

	m_vector_sorting_time = end_time - start_time;
}

template <typename T>
void PmergeMe<T>::sort_with_deque(void)
{
	m_comparisons = 0;
	auto start_time = std::chrono::system_clock::now();

	std::deque<PairUnit> pairs;

	int struggler = create_pairs(m_unsorted_deq, pairs);

	sort_big_numbers(pairs);

	std::deque<std::pair<int, size_t>> result;
	insert_small_numbers(pairs, result, struggler);

	m_sorted_deq.clear();

	for (size_t i = 0; i < result.size(); i++)
		m_sorted_deq.push_back(result[i].first);

	auto end_time = std::chrono::system_clock::now();

	m_deque_sorting_time = end_time - start_time;
}

template <typename T>
void PmergeMe<T>::sort(void)
{
	std::cout << "Before:\t"; 
	print_container(m_unsorted_vec);

	this->sort_with_vector();

	size_t vec_comparisons = m_comparisons;

	this->sort_with_deque();

	// size_t deq_comparisons = m_comparisons;

	std::cout << "After:\t";
	print_container(m_sorted_vec);

	std::cout << "Time to process a range of " << m_elements << " elements with std::vector : " << std::chrono::duration<double, std::micro>(m_vector_sorting_time).count() << " us\n";
	std::cout << "Time to process a range of " << m_elements << " elements with std::deque  : " << std::chrono::duration<double, std::micro>(m_deque_sorting_time).count() << " us\n";

	// std::cout << GREEN << "vec comparisons " << vec_comparisons << DEFAULT << std::endl;
	// std::cout << GREEN << "dec comparisons " << deq_comparisons << DEFAULT << std::endl;

	// // tester: (uses vec comparisons)
	std::cout << "comparisons " << vec_comparisons << std::endl;
}

// Operators
template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe<T>& other)
{
	if (this != &other)
	{
		this->m_vector_sorting_time = other.m_vector_sorting_time;
		this->m_deque_sorting_time = other.m_deque_sorting_time;
		this->m_elements = other.m_elements;
		this->m_comparisons = other.m_comparisons;
		this->m_unsorted_vec = other.m_unsorted_vec;
		this->m_sorted_vec = other.m_sorted_vec;
		this->m_unsorted_deq = other.m_unsorted_deq;
		this->m_sorted_deq = other.m_sorted_deq;

		// std::cout << BLUE << "PmergeMe copy assignment is called" << DEFAULT << std::endl;
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
