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



// =================================
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
template <typename Input>
int PmergeMe<T>::create_pairs(const Input& in, std::vector<PairUnit>& pairs)
{
    m_comparisons = 0;
    size_t id = 0;

    for (auto it = in.begin(); it != in.end();)
    {
        int a = *it++;
        if (it == in.end())
            return a; // struggler

        int b = *it++;

        if (a > b)
            pairs.push_back({a, b, id});
        else
            pairs.push_back({b, a, id});

        m_comparisons++;
        id++;
    }
    return -1;
}


template <typename T>
void PmergeMe<T>::split_pairs(const std::vector<PairUnit>& pairs, std::vector<int>& main, std::vector<std::pair<int, size_t>>& pend)
{
    for (auto& p : pairs)
    {
        main.push_back(p.big);
        pend.push_back({p.small, p.id});
    }
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

    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(v));
}

template <typename T>
template <typename Container>
typename Container::iterator PmergeMe<T>::binary_insert(Container& cont, int value)
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
void PmergeMe<T>::insert_pend(std::vector<int>& main, std::vector<std::pair<int, size_t>>& pend)
{
    std::vector<size_t> jacob = jacobsthal(pend.size());

    std::vector<bool> inserted(pend.size(), false);

    size_t prev = 0;

    for (size_t j = 1; j < jacob.size(); j++)
    {
        size_t cur = std::min(jacob[j], pend.size());

        for (size_t i = cur; i > prev; --i)
        {
            size_t idx = i - 1;

            if (inserted[idx])
                continue;

            auto pos = binary_insert(main, pend[idx].first);
            main.insert(pos, pend[idx].first);

            inserted[idx] = true;
        }

        prev = cur;
    }

    // safety (anything left)
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (!inserted[i])
        {
            auto pos = binary_insert(main, pend[i].first);
            main.insert(pos, pend[i].first);
        }
    }
}


template <typename T>
void PmergeMe<T>::sort_with_vector()
{
    std::vector<PairUnit> pairs;

    int stray = create_pairs(m_unsorted_vec, pairs);

    std::vector<int> main;
    std::vector<std::pair<int, size_t>> pend;

    split_pairs(pairs, main, pend);

    merge_sort(main);

    insert_pend(main, pend);

    if (stray != -1)
    {
        auto pos = binary_insert(main, stray);
        main.insert(pos, stray);
    }

    m_sorted_vec = main;
}


template <typename T>
void PmergeMe<T>::sort(void)
{
	std::cout << "Before:\t"; 
	print_container(m_unsorted_vec);

	this->sort_with_vector();

	size_t vec_comparisons = m_comparisons;

	// this->sort_with_deque();

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


// ======================================

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
