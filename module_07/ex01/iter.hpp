
#pragma once

#include <iostream>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"


template <typename T>
void print_array(T const  &element)
{
	std::cout << element << " ";
}

template <typename T>
void add_explenation_mark(T& element)
{
	element =  element + "!";
}

template <typename T>
void increment_array(T &element)
{
	element += 1;
}

template <typename T, std::size_t N>
std::size_t length_array(T (&arr)[N])
{
	(void)arr;
	return (N);
}

template <typename T, typename F>
void iter (T* array, int length, F* function)
{
	for (int i = 0; i < length; i++)
	{
		function(array[i]);
	}
}
