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
	size_t numbers_to_print = 6; // print all for tester to work

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
typename Container::iterator PmergeMe<T>::binary_search(Container& cont, int value)
{
    size_t left = 0;
	size_t right = cont.size();

    while (left < right)
    {
        size_t middle = (left + right) / 2;
        m_comparisons++;

        if (value < cont[middle])
            right = middle;
        else
            left = middle + 1;
    }
    return (cont.begin() + left);
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
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
    }
    return jacob;
}

template <typename T>
template <typename BigContainer, typename SmallContainer>
void PmergeMe<T>::insert_small_numbers(BigContainer& big_chain, SmallContainer& small_chain)
{
    const size_t size = small_chain.size();

    std::vector<size_t> jacob = jacobsthal(size);
    std::vector<bool> inserted(size, false);

    size_t prev = 0;

    for (size_t j = 1; j < jacob.size(); j++)
    {
        size_t cur = std::min(jacob[j], size);

        for (size_t i = cur; i > prev; i--)
        {
            size_t idx = i - 1;

            if (inserted[idx])
                continue;

            auto pos = binary_search(big_chain, small_chain[idx].first);
            big_chain.insert(pos, small_chain[idx].first);

            inserted[idx] = true;
        }
        prev = cur;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (!inserted[i])
        {
            auto pos = binary_search(big_chain, small_chain[i].first);
            big_chain.insert(pos, small_chain[i].first);
        }
    }
}

template <typename T>
template <typename Container>
void PmergeMe<T>::merge(Container& cont, const Container& left, const Container& right)
{
    typename Container::const_iterator left_it = left.begin();
    typename Container::const_iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end())
    {
        if (*left_it <= *right_it)
            cont.push_back(*left_it++);
        else
            cont.push_back(*right_it++);
    }

    while (left_it != left.end())
        cont.push_back(*left_it++);

    while (right_it != right.end())
        cont.push_back(*right_it++);
}

template <typename T>
template <typename Container>
void PmergeMe<T>::merge_sort(Container& cont)
{
    if (cont.size() <= 1)
        return;

    size_t mid = cont.size() / 2;

    Container left(cont.begin(), cont.begin() + mid);
    Container right(cont.begin() + mid, cont.end());

    merge_sort(left);
    merge_sort(right);

    cont.clear();

    merge(cont, left, right);
}

template <typename T>
template <typename PairContainer, typename BigContainer, typename SmallContainer>
void PmergeMe<T>::split_pairs(const PairContainer& pairs, BigContainer& big_chain, SmallContainer& small_chain)
{
    for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        big_chain.push_back(it->big);
        small_chain.push_back(std::make_pair(it->small, it->id));
    }
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
			return first;

		int second = *it++;

		if (first > second)
			pairs.push_back(PairUnit(first, second, id));
		else
			pairs.push_back(PairUnit(second, first, id));

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
    std::vector<int> big_chain;
    std::vector<std::pair<int, size_t>> small_chain;

    int stray = create_pairs(m_unsorted_vec, pairs);
	
    split_pairs(pairs, big_chain, small_chain);

    merge_sort(big_chain);

    insert_small_numbers(big_chain, small_chain);

    if (stray != -1)
    {
        auto pos = binary_search(big_chain, stray);
        big_chain.insert(pos, stray);
    }

    m_sorted_vec = big_chain;
		
	auto end = clock::now();

	m_vector_sorting_time = std::chrono::duration<double, std::micro>(end - start);
}

template <typename T>
void PmergeMe<T>::sort_with_deque()
{
	using clock = std::chrono::high_resolution_clock;
	auto start = clock::now();

    std::deque<PairUnit> pairs;
    std::deque<int> big_chain;
    std::deque<std::pair<int, size_t>> small_chain;
	
    int stray = create_pairs(m_unsorted_deq, pairs);

    split_pairs(pairs, big_chain, small_chain);
    
    merge_sort(big_chain);

    insert_small_numbers(big_chain, small_chain);

    if (stray != -1)
    {
        auto pos = binary_search(big_chain, stray);
        big_chain.insert(pos, stray);
    }

    m_sorted_deq = big_chain;

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
    size_t deq_comparisons = m_comparisons;

	std::cout << "After:\t";
	print_container(m_sorted_vec);

	std::cout << "Time to process a range of " << m_elements << " elements with std::vector : " << m_vector_sorting_time.count() << " us\n";
	std::cout << "Time to process a range of " << m_elements << " elements with std::deque  : " << m_deque_sorting_time.count() << " us\n";

	std::cout << "vec comparisons : " << vec_comparisons << std::endl;
	std::cout << "dec comparisons : " << deq_comparisons << std::endl;

	// // easy print for tester
	// std::cout << "comparisons " << vec_comparisons << std::endl;
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
