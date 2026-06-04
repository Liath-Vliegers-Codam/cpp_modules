

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

	for (typename Container::const_iterator it = input_container.begin(); it != input_container.end(); it++)
	{
		m_unsorted_vec.push_back(*it);
		m_unsorted_deq.push_back(*it);
		m_elements++;
	}
	// std::cout << BLUE << "PmergeMe parameterized constructor is called" << DEFAULT << std::endl;
	
	// //========= DEBUG ========
	// std::cout << YELLOW << "== INPUT after constructor: ==" << std::endl;
	// print_container(m_unsorted_deq, "DEQUE: ");
	// print_container(m_unsorted_vec, "VECTOR: ");
	// std::cout << "Elements: " << m_elements << DEFAULT << std::endl;
	// //========================
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


// Member functions

// template <typename T>
// template <typename PairContainer>
// void PmergeMe<T>::print_big_numbers(const PairContainer &pairs_array)
// {
//     std::cout << "BIG NUMBERS:" << std::endl;
//     for (const auto &it : pairs_array)
//         std::cout << it.big << " - id = " << it.id << std::endl;
//     std::cout << "==============" << std::endl;
// }

// template <typename T>
// template <typename PairContainer>
// void PmergeMe<T>::print_small_numbers(const PairContainer &pairs_array)
// {
//     std::cout << "SMALL NUMBERS:" << std::endl;
//     for (const auto &it : pairs_array)
//         std::cout << it.small << " - id = " << it.id << std::endl;
//     std::cout << "==============" << std::endl;
// }

template <typename T>
template <typename InputContainer, typename OutputContainer>
int PmergeMe<T>::parse_pairs(InputContainer unsorted_array, OutputContainer &pairs)
{
	typename InputContainer::const_iterator it = unsorted_array.begin();
	size_t id = 0;
	
    while (it != unsorted_array.end())
    {
        int first = *it;
        ++it;

        if (it == unsorted_array.end())
            return (first); // struggler

        int second = *it;
        ++it;

        if (first > second)  // comparison
        {
			pairs.push_back(PairUnit{first, second, id});
        }
        else
        {
            pairs.push_back(PairUnit{second, first, id});
        }
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
    ++it;

    for (; it != pairs.end(); ++it)
    {
        size_t left = 0;
        size_t right = sorted.size();

        while (left < right)
        {
            size_t mid = left + (right - left) / 2;
            ++m_comparisons;
            if (it->big < sorted[mid].big)
                right = mid;
            else
                left = mid + 1;
        }

        sorted.insert(sorted.begin() + static_cast<typename Container::difference_type>(left), *it);
    }

    pairs.swap(sorted);
}



//  version 3

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
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        result.push_back(std::make_pair(pairs[i].big, pairs[i].id));
        big_pos[pairs[i].id] = i;
    }

// ============= jacob shit starts ================
	size_t processed = 1;

	std::vector<size_t> jac;
	jac.push_back(1);
	jac.push_back(1);
	while (jac.back() < pairs.size())
	{
		size_t s = jac.size();
		jac.push_back(jac[s - 1] + 2 * jac[s - 2]);
	}

	result.insert(result.begin(), std::make_pair(pairs[0].small, pairs[0].id));
	for (size_t i = 0; i < big_pos.size(); ++i)
		++big_pos[i];

	for (size_t k = 0; k < jac.size(); ++k)
	{
		size_t boundary = jac[k];
		if (boundary <= processed)
			continue;
		if (boundary > pairs.size())
			boundary = pairs.size();

		for (size_t idx = boundary; idx > processed; --idx)
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
				++m_comparisons;
				if (small_val < result[mid].first)
					right = mid;
				else
					left = mid + 1;
			}

			result.insert(result.begin() + static_cast<typename ResultContainer::difference_type>(left),
						std::make_pair(small_val, pair_id));

			for (size_t i = 0; i < big_pos.size(); ++i)
			{
				if (big_pos[i] >= left)
					++big_pos[i];
			}
		}

		processed = boundary;
		if (processed >= pairs.size())
			break;
	}
// ============= jacob shit ends ================


    if (struggler != -1)
    {
        size_t left = 0;
        size_t right = result.size();
        while (left < right)
        {
            size_t mid = left + (right - left) / 2;
            ++m_comparisons;
            if (struggler < result[mid].first)
                right = mid;
            else
                left = mid + 1;
        }

        result.insert(result.begin() + static_cast<typename ResultContainer::difference_type>(left),
                      std::make_pair(struggler, static_cast<size_t>(-1)));
    }
}


template <typename T>
void PmergeMe<T>::sort_with_vector(void)
{
	auto start_time = std::chrono::system_clock::now();

	std::vector<PairUnit> pairs;

	int struggler = parse_pairs(m_unsorted_vec, pairs);
	
	// ==== DEBUG ====
	// print_big_numbers(pairs);
	// print_small_numbers(pairs);
	// std::cout << "struggler: " << struggler << std::endl;
	// ===============

	sort_big_numbers(pairs);

	for (size_t i = 0; i < pairs.size(); i++)
	{
		m_sorted_vec.push_back(pairs[i].big);
	}

    std::vector<std::pair<int, size_t>> result;
	insert_small_numbers(pairs, result, struggler);

	// copy final values into m_sorted_vec
    m_sorted_vec.clear();
    for (size_t i = 0; i < result.size(); i++)
        m_sorted_vec.push_back(result[i].first);

    auto end_time = std::chrono::system_clock::now();

    m_vector_sorting_time = end_time - start_time;
}

template <typename T>
void PmergeMe<T>::sort_with_deque(void)
{
	auto start_time = std::chrono::system_clock::now();

	std::deque<PairUnit> pairs;

	int struggler = parse_pairs(m_unsorted_deq, pairs);
	
	// ==== DEBUG ====
	// print_big_numbers(pairs);
	// print_small_numbers(pairs);
	// std::cout << "struggler: " << struggler << std::endl;
	// ===============

	sort_big_numbers(pairs);

	for (size_t i = 0; i < pairs.size(); i++)
	{
		m_sorted_deq.push_back(pairs[i].big);
	}

    std::deque<std::pair<int, size_t>> result;
	insert_small_numbers(pairs, result, struggler);

	// copy final values into m_sorted_deq
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

	m_comparisons = 0;
    this->sort_with_vector();
	// std::cout << YELLOW << "Comparisons vector: " << m_comparisons << DEFAULT << std::endl;
	
	m_comparisons = 0;
    this->sort_with_deque();
	// std::cout << YELLOW << "Comparisons deque: " << m_comparisons << DEFAULT << std::endl;

    std::cout << "After:\t";
	print_container(m_sorted_vec);

	std::cout << "Time to process a range of " << m_elements << " elements with std::vector : "
			  << std::chrono::duration<double, std::micro>(m_vector_sorting_time).count() << " us\n";
	std::cout << "Time to process a range of " << m_elements << " elements with std::deque  : "
			  << std::chrono::duration<double, std::micro>(m_deque_sorting_time).count() << " us\n";


	std::cout << "comparisons " << m_comparisons << std::endl;
	
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
