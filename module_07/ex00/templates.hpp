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
T max (T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T>
T min (T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T>
void swap (T &a, T &b)
{
	T temp = a;

	a = b;
	b = temp;
}
