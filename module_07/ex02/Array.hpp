#pragma once

# include <iostream>
# include <stdexcept>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

template <typename T>
class Array
{
	private:
		T*		_data;
		size_t	_size;

	public:
		// Member functions
		size_t size();

		// Getters and Setters

		// Constructors
		Array(void);
		Array(size_t n);
		Array(const Array& other);

		// Destructors
		~Array();

		// Overload operators
		Array &operator=(const Array& other);
		T& operator[](size_t index);
};

#include "Array.tpp"
