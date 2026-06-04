

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
	
	//========= DEBUG ========
	std::cout << YELLOW << "== INPUT after constructor: ==" << std::endl;
	print_container(m_unsorted_deq, "DEQUE: ");
	print_container(m_unsorted_vec, "VECTOR: ");
	std::cout << "Elements: " << m_elements << DEFAULT << std::endl;
	//========================
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
template <typename PairContainer>
void PmergeMe<T>::print_big_numbers(const PairContainer &pairs_array)
{
    std::cout << "BIG NUMBERS:" << std::endl;
    for (const auto &it : pairs_array)
        std::cout << it.big << " - id = " << it.id << std::endl;
    std::cout << "==============" << std::endl;
}

template <typename T>
template <typename PairContainer>
void PmergeMe<T>::print_small_numbers(const PairContainer &pairs_array)
{
    std::cout << "SMALL NUMBERS:" << std::endl;
    for (const auto &it : pairs_array)
        std::cout << it.small << " - id = " << it.id << std::endl;
    std::cout << "==============" << std::endl;
}

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

		m_vector_comparisons++;
        if (first > second)
        {
			pairs.push_back(PairUnit{first, second, id});
        }
        else
        {
            pairs.push_back(PairUnit{second, first, id});
        }
		id++;
    }
    return (-1);
}



template <typename T>
template <typename Container>
void PmergeMe<T>::merge(Container &array, int left, int middle, int right)
{
	// create temporary containers for left and right halves
    Container left_half(array.begin() + left, array.begin() + middle + 1);
    Container right_half(array.begin() + middle + 1, array.begin() + right + 1);
    
    size_t i = 0;
	size_t j = 0;
	size_t k = left;
    
    // merge by comparing front elements
    while (i < left_half.size() && j < right_half.size())
    {
        if (left_half[i].big <= right_half[j].big)
        {
            array[k++] = left_half[i++];
        }
        else
        {
            array[k++] = right_half[j++];
        }
        m_vector_comparisons++;
    }
    
    // copy any remaining elements
    while (i < left_half.size())
        array[k++] = left_half[i++];
    while (j < right_half.size())
        array[k++] = right_half[j++];
}


template <typename T>
template <typename Container>
void PmergeMe<T>::merge_sort(Container &array, int left, int right)
{
	// base case, we reached the middle
	if (left >= right)
		return ;

	// find middle
	int middle = left + (right - left) / 2;

	// recursivly sort left half
	merge_sort(array, left, middle);

	// recursivly sort right half
	merge_sort(array, middle + 1, right);
	
	// merge the sorted halves
	merge(array, left, middle, right);

}



template <typename T>
template <typename Container>
void PmergeMe<T>::sort_big_numbers(Container &pairs)
{
	std::cout << MAGENTA << "let the BIG sorting begin!" << DEFAULT << std::endl;
	
	if (pairs.size() < 2)
		return ;

	merge_sort(pairs, 0, pairs.size() - 1);

}



template <typename ResultContainer>
void PmergeMe<T>::bounded_insert(ResultContainer& result, int val, size_t id, size_t upper)
{
    size_t left = 0;
    size_t right = upper; // exclusive
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        ++m_vector_comparisons; // count the comparison
        if (val < result[mid].first)
            right = mid;
        else
            left = mid + 1;
    }
    result.insert(result.begin() + static_cast<std::vector<std::pair<int,size_t>>::difference_type>(left), std::make_pair(val, id));
}


template <typename T>
template <typename PairContainer, typename ResultContainer>
void PmergeMe<T>::insert_small_numbers(PairContainer& pairs, ResultContainer& result, int struggler)
{
    std::cout << MAGENTA << "let the SMALL insertion begin!" << DEFAULT << std::endl;

    if (pairs.empty())
    {
        if (struggler != -1)
            m_sorted_vec.push_back(struggler);
        return;
    }

    // result stores pairs of (value, id) so we can find a big by id later
    ResultContainer<std::pair<int, size_t>> result;
    result.reserve((pairs.size() * 2) + (struggler != -1 ? 1 : 0));

    // start result with the sorted big values (in current order of pairs)
    for (size_t i = 0; i < pairs.size(); ++i)
        result.push_back(std::make_pair(pairs[i].big, pairs[i].id));

    // Insert the very first small with zero comparisons (it always goes before first big)
    result.insert(result.begin(), std::make_pair(pairs[0].small, pairs[0].id));
    size_t processed = 1; // number of pair indices already handled (1-based)

    // Build Jacobsthal sequence: 1,1,3,5,11,... until >= pairs.size()
    ResultContainer<size_t> jac;
    jac.push_back(1);
    jac.push_back(1);
    while (jac.back() < pairs.size())
    {
        size_t s = jac.size();
        size_t next = jac[s - 1] + 2 * jac[s - 2];
        jac.push_back(next);
        s = jac.size();
    }

    // Process Jacobsthal boundaries (1-based indices)
    for (size_t k = 0; k < jac.size(); k++)
    {
        size_t boundary = jac[k];
        if (boundary <= processed)
            continue;
        if (boundary > pairs.size())
            boundary = pairs.size();

        // iterate backwards from `boundary` down to processed+1 (1-based)
        for (size_t idx = boundary; idx > processed; --idx)
        {
            size_t pair_index = idx - 1; // convert to 0-based
            int small_val = pairs[pair_index].small;
            size_t pair_id = pairs[pair_index].id;

            // find where this pair's big currently sits in `result`
            size_t big_pos = result.size(); // default: not found -> insert at end
            for (size_t p = 0; p < result.size(); ++p)
            {
                if (result[p].second != pair_id)
                    continue;
                ++m_vector_comparisons; // comparing result[p].first with the pair's big
                if (result[p].first == pairs[pair_index].big)
                {
                    big_pos = p;
                    break;
                }
            }

            // insert small before its big (search restricted to [0, big_pos) )
            bounded_insert(result, small_val, pair_id, big_pos);
        }

        processed = boundary;
        if (processed >= pairs.size())
            break;
    }

    // insert the struggler (if any) across the full result
    if (struggler != -1)
        bounded_insert(result, struggler, static_cast<size_t>(-1), result.size());

    // copy final values into m_sorted_vec
    m_sorted_vec.clear();
    m_sorted_vec.reserve(result.size());
    for (size_t i = 0; i < result.size(); ++i)
        m_sorted_vec.push_back(result[i].first);
}



template <typename T>
void PmergeMe<T>::sort_with_vector(void)
{
	std::cout << MAGENTA << "let the sorting with vector begin" << DEFAULT << std::endl;
	
	auto start_time = std::chrono::system_clock::now();

	std::vector<PairUnit> pairs;
	pairs.reserve(m_elements / 2);

	int struggler = parse_pairs(m_unsorted_vec, pairs);
	
	// ==== DEBUG ====
	print_big_numbers(pairs);
	print_small_numbers(pairs);
	std::cout << "struggler: " << struggler << std::endl;
	// ===============

	sort_big_numbers(pairs);

	m_sorted_vec.reserve(m_elements);
	for (size_t i = 0; i < pairs.size(); i++)
	{
		m_sorted_vec.push_back(pairs[i].big);
	}

    std::vector<std::pair<int, size_t>> result;
	insert_small_numbers(pairs, result, struggler);

    auto end_time = std::chrono::system_clock::now();

    m_vector_sorting_time = end_time - start_time;
}

// template <typename T>
// void PmergeMe<T>::sort_with_deque(void)
// {
		//	same as sort with vector but with deque
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

    // std::cout << "Time to process a range of " << m_elements << " elements with std::vector : " << (m_vector_sorting_time / 1000) << " us\n";
    // std::cout << "Time to process a range of " << m_elements << " elements with std::deque  : " << (m_deque_sorting_time / 1000) << " us\n";

	std::cout << "Time to process a range of " << m_elements << " elements with std::vector : "
			  << std::chrono::duration<double, std::micro>(m_vector_sorting_time).count() << " us\n";
	std::cout << "Time to process a range of " << m_elements << " elements with std::deque  : "
			  << std::chrono::duration<double, std::micro>(m_deque_sorting_time).count() << " us\n";
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
