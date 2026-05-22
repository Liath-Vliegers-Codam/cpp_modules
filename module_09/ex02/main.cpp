/*
	You must create a program with these constraints:
	• The name of the program is PmergeMe.
	• Your program must be able to use a positive integer sequence as an argument.
	• Your program must use the merge-insert sort algorithm to sort the positive integer  sequence.
	To clarify, yes, you need to use the Ford-Johnson algorithm. (source: Art Of Computer Programming, Vol.3. Merge Insertion, Page 184. (page 196 in the pdf))
	• If an error occurs during program execution, an error message should be displayed on the standard error.
	
	You must use at least two different containers in your code to validate this exercise. Your program must be able to handle at least 3000 different integers.

	It is strongly advised to implement your algorithm for each container and thus to avoid using a generic function.
	
	Here are some additional guidelines on the information you should display line by line on the standard output:
	• On the first line you must display an explicit text followed by the unsorted positive integer sequence.
	• On the second line you must display an explicit text followed by the sorted positive integer sequence.
	• On the third line, you must display an explicit message indicating the time taken by your algorithm, specifying the first container used to sort the positive integer sequence.
	• On the last line you must display an explicit text indicating the time used by your algorithm by specifying the second container used to sort the positive integer sequence.
	
	The format for the display of the time used to carry out your sorting is free but the precision chosen must allow to clearly see the difference between the two containers used.
	
	Here is an example of standard use:
	
		$> ./PmergeMe 3 5 9 7 4
		Before:	3 5 9 7 4
		After:	3 4 5 7 9
		Time to process a range of 5 elements with std::[..] : 0.00031 us
		Time to process a range of 5 elements with std::[..] : 0.00014 us
		
		$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
		Before:	141 79 526 321 [...]
		After:	79 141 321 526 [...]
		Time to process a range of 3000 elements with std::[..] : 62.14389 us
		Time to process a range of 3000 elements with std::[..] : 69.27212 us
		
		$> ./PmergeMe "-1" "2"
		Error
		
	
	The indication of the time is deliberately strange in this example.
	Of course you have to indicate the time used to perform all your operations, both the sorting part and the data management part.

	Warning: The container(s) you used in the previous exercises are forbidden here.
	The management of errors related to duplicates is left to your discretion.

*/

#include "PmergeMe.hpp"

void print_vector(std::vector<int> vector)
{
	for (int x : vector)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
}


bool check_token(std::string token)
{
	for (size_t i = 0; i < token.length(); i++)
	{
		if (!isdigit(token[i]))
			return (false);
	}
	return (true);
}


std::vector<int> parse_input(std::string input)
{
	std::vector<int> parsed_input_vec;
	std::stringstream sstream(input);
	std::string token;

	while (sstream >> token)
	{
		std::cout << YELLOW << "token = " << token << DEFAULT << std::endl;
		if (!check_token(token))
		{
			throw std::runtime_error("Error (check_token() failed (invalid token))");
		}

		int parsed_input;
		try
		{
			parsed_input = stoi(token);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("Error (stoi() failed (probably overflow))");
		}

		parsed_input_vec.push_back(parsed_input);
	}

	return (parsed_input_vec);
}


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << RED << "Error: This program must use a positive integer sequence as an argument" << DEFAULT << std::endl;
		return (EXIT_FAILURE);
	}

	// parse input
	std::vector<int> parsed_input_vec;
	try
	{
		for (int i = 1; argv[i] != NULL; i++)
		{
			std::cout << GREEN << "input #" << i << " = " << argv[i] << DEFAULT << std::endl;
			std::vector<int> part = parse_input(argv[i]);
    		parsed_input_vec.insert(parsed_input_vec.end(), part.begin(), part.end());
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::cout << GREEN << "before: "; print_vector(parsed_input_vec); std::cout << DEFAULT << std::endl;

	// sort input



	
	return (EXIT_SUCCESS);
}

