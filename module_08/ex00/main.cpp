#include "easyfind.hpp"

template <typename T>
void find_with_easyfind(T container, int value)
{
	std::cout << BLUE << "Searching for value " << value << DEFAULT << std::endl;
	try
	{
		easyfind(container, value);
		std::cout << GREEN << "Value was found in the container!" << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}
}

int main(void)
{
	std::array<int, 10> arr1 = {1, 15, 234, 4, 94, 59, 60, 88, 2147483647, 10};
	
	std::vector<int> vec1 = {1, 15, 234, 4, 94, 59, 60, 88, 2147483647, 10};

	std::deque<int> deq1 = {1, 15, 234, 4, 94, 59, 60, 88, 2147483647, 10};

	std::list<int> list1 = {1, 15, 234, 4, 94, 59, 60, 88, 2147483647, 10};

	std::forward_list<int> flist1 = {1, 15, 234, 4, 94, 59, 60, 88, 2147483647, 10};

	std::cout << MAGENTA << "All containers look like this:   1, 15, 234, 4, 94, 59, 60, 88, 2147483647, 10" << DEFAULT << std::endl;

	std::cout << YELLOW << "TEST WITH ARRAY" << DEFAULT << std::endl;
	find_with_easyfind(arr1, 1);
	find_with_easyfind(arr1, 2);
	std::cout << YELLOW << "TEST WITH VECTOR" << DEFAULT << std::endl;
	find_with_easyfind(vec1, 15);
	find_with_easyfind(vec1, 16);
	std::cout << YELLOW << "TEST WITH DEQUE" << DEFAULT << std::endl;
	find_with_easyfind(deq1, 234);
	find_with_easyfind(deq1, 235);
	std::cout << YELLOW << "TEST WITH LIST" << DEFAULT << std::endl;
	find_with_easyfind(list1, 88);
	find_with_easyfind(list1, 89);
	std::cout << YELLOW << "TEST WITH FORWARD LIST" << DEFAULT << std::endl;
	find_with_easyfind(flist1, 2147483647);
	find_with_easyfind(flist1, 2147483646);

	return (0);
}
