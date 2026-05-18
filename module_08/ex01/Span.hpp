#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <set>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class Span
{
	private:
		size_t 				_max_size;
		size_t 				_size;
		std::vector<int> 	_vec;

	public:
		// Constructors
		Span(size_t N);
		Span(const Span& other);

		// Destructor
		~Span(void);

		// Operators
		Span &operator=(const Span& other);

		// Getters and Setters
		std::vector<int> get_vec();

		// Member functions
		void addNumber(int nbr);
		size_t shortestSpan();
		size_t longestSpan();

		template <typename ItType>
		void addRange(ItType start_it, ItType end_it)
		{
			size_t range_size = std::distance(start_it, end_it);

			if (range_size < 0)
			{
				throw std::runtime_error("The end iterator is smaller than the start iterator");
			}
			if (_size + range_size > _max_size)
			{
				throw std::runtime_error("Range exceeds max size of this Span object");
			}
			while (start_it != end_it)
			{
				_vec.push_back(*start_it);
				_size++;
				start_it++;
			}
		};
};

std::ostream& operator<<(std::ostream &output_stream, Span& src);
