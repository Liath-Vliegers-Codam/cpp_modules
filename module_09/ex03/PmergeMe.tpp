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
	m_elements = 0;
	m_comparisons = 0;
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
template <typename Container>
void PmergeMe<T>::print_container(const Container &cont)
{
	typename Container::const_iterator it_start = cont.begin(); 
	typename Container::const_iterator it_end = cont.end();
	size_t dist = std::distance(it_start, it_end);
	size_t numbers_to_print = 60000; // print all for tester to work

	if (dist > numbers_to_print)
	{
		for (; it_start != cont.begin() + numbers_to_print; it_start++)
		{
			std::cout << *it_start << " ";
		}
		std::cout << "[...]";
		std::cout << std::endl;
	}

	else
	{
		for (; it_start != it_end; it_start++)
		{
			std::cout << *it_start << " ";
		}
		std::cout << std::endl;
	}
}

template <typename T>
template <typename Container>
typename Container::iterator PmergeMe<T>::binary_search_until(Container& chain, int value, size_t limit_index)
{
    size_t left = 0;
    size_t right = limit_index;

    while (left < right)
    {
        size_t mid = (left + right) / 2;

        if (value < chain[mid].value) // comparison
            right = mid;
        else
            left = mid + 1;

		m_comparisons++;
    }

    return (chain.begin() + left);
}

template <typename T>
std::vector<size_t> PmergeMe<T>::jacobsthal(size_t n)
{
    std::vector<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(1);

    while (jacob.back() < n)
    {
        size_t i = jacob.size();
        jacob.push_back(jacob[i - 1] + (2 * jacob[i - 2]));
    }
    return (jacob);
}

template <typename T>
template <typename Container>
size_t PmergeMe<T>::find_position(const Container& chain, size_t id)
{
    for (size_t i = 0; i < chain.size(); i++)
    {
        if (chain[i].id == id)
            return (i);
    }
    return (chain.size());
}

template <typename T>
template <typename ResultContainer, typename Container>
void PmergeMe<T>::insert_small_chain(ResultContainer& result_chain, Container& small_chain)
{
    size_t size = small_chain.size();
    std::vector<size_t> jacob = jacobsthal(size);
    std::vector<bool> inserted(size, false);
    size_t prev = 0;
	typename ResultContainer::iterator pos;

    for (size_t j = 1; j < jacob.size(); j++)
    {
        size_t cur = std::min(jacob[j], size);
        for (size_t i = cur; i > prev; i--)
        {
            size_t idx = i - 1;

            if (inserted[idx])
                continue;

            PairUnit& p = small_chain[idx];
            size_t limit_index = find_position(result_chain, p.id);
            pos = binary_search_until(result_chain, p.small, limit_index);
            
			result_chain.insert(pos, BigNode{p.small, p.id});
            inserted[idx] = true;
        }
        prev = cur;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (inserted[i])
            continue;

        PairUnit& p = small_chain[i];
        size_t limit_index = find_position(result_chain, p.big);
        pos = binary_search_until(result_chain, p.small, limit_index);
        
		result_chain.insert(pos, BigNode{p.small, p.id});
        inserted[i] = true;
    }
}

template <typename T>
template <typename PairContainer, typename ResultContainer, typename Container>
void PmergeMe<T>::build_chains(PairContainer& pairs, ResultContainer& result_chain, Container& small_chain)
{
	if (!pairs.empty())
	{
		// build result_chain
		result_chain.push_back(BigNode{pairs[0].small, pairs[0].id});

		for (size_t i = 0; i < pairs.size(); i++)
		{
			result_chain.push_back(BigNode{pairs[i].big, pairs[i].id});
		}

		// build small_chain
		for (size_t i = 1; i < pairs.size(); i++)
			small_chain.push_back(pairs[i]);
	}
}

template <typename T>
template <typename PairContainer>
void PmergeMe<T>::merge_pairs(PairContainer& pairs, const PairContainer& left, const PairContainer& right)
{
    typename PairContainer::const_iterator left_it = left.begin();
    typename PairContainer::const_iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end())
    {
        if (left_it->big <= right_it->big) // comparison
            pairs.push_back(*left_it++);
        else
            pairs.push_back(*right_it++);

		m_comparisons++;
    }

    while (left_it != left.end())
        pairs.push_back(*left_it++);

    while (right_it != right.end())
        pairs.push_back(*right_it++);
}

template <typename T>
template <typename PairContainer>
void PmergeMe<T>::merge_sort_pairs(PairContainer& pairs)
{
    if (pairs.size() <= 1)
        return;

    size_t mid = pairs.size() / 2;

    PairContainer left(pairs.begin(), pairs.begin() + mid);
    PairContainer right(pairs.begin() + mid, pairs.end());

    merge_sort_pairs(left);
    merge_sort_pairs(right);

    pairs.clear();

    merge_pairs(pairs, left, right);
}

template <typename T>
template <typename InputContainer, typename PairContainer>
int PmergeMe<T>::create_pairs(const InputContainer& input, PairContainer& pairs)
{
    size_t id = 0;
	typename InputContainer::const_iterator it = input.begin();

	while (it != input.end())
	{
		int first = *it++;

		if (it == input.end())
			return (first);

		int second = *it++;

		if (first > second) // comparison
			pairs.push_back(PairUnit(first, second, id));
		else
			pairs.push_back(PairUnit(second, first, id));

		m_comparisons++;
		id++;
    }
    return (-1);
}

template <typename T>
void PmergeMe<T>::sort_with_vector()
{
	using clock = std::chrono::high_resolution_clock;
	auto start = clock::now();

    std::vector<PairUnit> pairs;
	std::vector<BigNode> result_chain;
	std::vector<PairUnit> small_chain;

    int struggler = create_pairs(m_unsorted_vec, pairs);
    merge_sort_pairs(pairs);
	build_chains(pairs, result_chain, small_chain);
	insert_small_chain(result_chain, small_chain);

    if (struggler != -1)
    {
        auto pos = binary_search_until(result_chain, struggler, result_chain.size());
        result_chain.insert(pos, BigNode{struggler, std::numeric_limits<size_t>::max()});
    }

	m_sorted_vec.clear();
	for (size_t i = 0; i < result_chain.size(); i++)
		m_sorted_vec.push_back(result_chain[i].value);
		
	auto end = clock::now();

	m_vector_sorting_time = std::chrono::duration<double, std::micro>(end - start);
}

template <typename T>
void PmergeMe<T>::sort_with_deque()
{
	using clock = std::chrono::high_resolution_clock;
	auto start = clock::now();

    std::deque<PairUnit> pairs;
	std::deque<BigNode> result_chain;
	std::deque<PairUnit> small_chain;

    int struggler = create_pairs(m_unsorted_deq, pairs);
    merge_sort_pairs(pairs);
	build_chains(pairs, result_chain, small_chain);
	insert_small_chain(result_chain, small_chain);

    if (struggler != -1)
    {
        auto pos = binary_search_until(result_chain, struggler, result_chain.size());
        result_chain.insert(pos, BigNode{struggler, std::numeric_limits<size_t>::max()});
    }

	m_sorted_deq.clear();
	for (size_t i = 0; i < result_chain.size(); i++)
		m_sorted_deq.push_back(result_chain[i].value);
		
	auto end = clock::now();

	m_deque_sorting_time = std::chrono::duration<double, std::micro>(end - start);
}

template <typename T>
void PmergeMe<T>::sort(void)
{
	std::cout << "Before:\t"; 
	print_container(m_unsorted_vec);

	// VECTOR
	m_comparisons = 0;
	sort_with_vector();
	size_t vec_comparisons = m_comparisons;

    // DEQUE
    m_comparisons = 0;
    sort_with_deque();
    // size_t deq_comparisons = m_comparisons;

	std::cout << "After:\t";
	print_container(m_sorted_vec);

	std::cout << "Time to process a range of " << m_elements << " elements with std::vector : " << m_vector_sorting_time.count() << " us\n";
	std::cout << "Time to process a range of " << m_elements << " elements with std::deque  : " << m_deque_sorting_time.count() << " us\n";

	// std::cout << "vec comparisons : " << vec_comparisons << std::endl;
	// std::cout << "dec comparisons : " << deq_comparisons << std::endl;

	// // easy print for tester
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
