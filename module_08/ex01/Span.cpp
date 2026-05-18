#include "Span.hpp"

// Constructors
Span::Span(size_t max_size) : _max_size(max_size), _size(0)
{
	std::cout << BLUE << "Span parameterized constructor is called" << DEFAULT << std::endl;
}

Span::Span(const Span& other)
{
	_max_size = other._max_size;
	_size = other._size;
	_vec = other._vec;
	std::cout << BLUE << "Span copy constructor is called" << DEFAULT << std::endl;
}

// Destructor
Span::~Span(void)
{
    std::cout << BLUE << "Span destructor is called" << DEFAULT << std::endl;
}

// Getters and Setters
std::vector<int> Span::get_vec()
{
	return (_vec);
}

// Member functions
void Span::addNumber(int nbr)
{
	if (_size == _max_size)
	{
		throw std::runtime_error("This Span object has reached it's maximum size");
	}
	else
	{
		_vec.push_back(nbr);
		_size++;
		std::cout << GREEN << "Added " << nbr << " to this Span.	Size is now " << _size << DEFAULT << std::endl;
	}
}

size_t Span::shortestSpan()
{
	if (_size < 2)
	{
		throw std::runtime_error("This Span object has too few elements to find the shortest span");
	}

	size_t distance;
	size_t shortest_distance = SIZE_MAX;
	std::multiset<int>	sorted_mset(_vec.begin(), _vec.end());

    std::multiset<int>::iterator it = std::next(sorted_mset.begin(), 1); 	// index 1
    std::multiset<int>::iterator prev_it = sorted_mset.begin();				// index 0

	while (it != sorted_mset.end())
	{
		distance = *it - *prev_it;
		if (shortest_distance > distance)
		{
			shortest_distance = distance;
		}
		it++;
		prev_it++;
	}
	return (shortest_distance);
}

size_t Span::longestSpan()
{
	if (_size < 2)
	{
		throw std::runtime_error("This Span object has too few elements to find the longest span");
	}
	
	std::multiset<int>	sorted_mset(_vec.begin(), _vec.end());

    std::multiset<int>::iterator first_it = sorted_mset.begin();
    std::multiset<int>::iterator last_it = std::prev(sorted_mset.end());
	size_t distance = *last_it - *first_it;

	return (distance);
}

// Overload operators
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_max_size = other._max_size;
		_size = other._size;
		_vec = other._vec;
		std::cout << "Span copy assignment is called" << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& output_stream, Span& src)
{
	std::vector<int> vec = src.get_vec();
	output_stream << "This Span object contains the numbers: [";

	for (size_t i = 0; i < vec.size(); ++i)
	{
		output_stream << vec[i];
		if (i < vec.size() - 1)
			output_stream << ", ";
	}

	output_stream << "]";
	return (output_stream);
}
