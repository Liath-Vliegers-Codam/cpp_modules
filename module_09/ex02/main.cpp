#include "PmergeMe.hpp"
#include "parser.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << RED << "Error: This program must use a positive integer sequence as an argument" << DEFAULT << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<int> input_vec;
	std::deque<int> input_deq;

	try
	{
		input_vec = parse_input<std::vector<int>>(argv + 1);
		input_deq = parse_input<std::deque<int>>(argv + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
		return (EXIT_FAILURE);
	}

	PmergeMe<int> merger_vec(input_vec);
	merger_vec.sort();

	// // PmergeMe<int> merger_deq(input_deq);
	// // merger_deq.sort();
	
	return (EXIT_SUCCESS);
}
