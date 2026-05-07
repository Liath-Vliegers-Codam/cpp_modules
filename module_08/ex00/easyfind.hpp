
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <forward_list>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

template <typename T>
typename T::iterator easyfind(T container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	// auto it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
	{
		return (it);
	}
	else
	{
		throw std::runtime_error("Value not found in the container");
	}
}
