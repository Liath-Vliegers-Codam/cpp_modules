

// Try to make it smaller than jisses program: < 56 lines :)

// Explanation

// In reverse Polish notation, the operators follow their operands. 
// For example, to add 3 and 4 together, the expression is 3 4 + rather than 3 + 4. 
// The conventional notation expression 3 − 4 + 5 becomes 3 4 − 5 + in reverse Polish notation: 4 is first subtracted from 3, then 5 is added to it.

// The concept of a stack, a last-in/first-out construct, is integral to the left-to-right evaluation of RPN. 
// In the example 3 4 −, first the 3 is put onto the stack, then the 4; the 4 is now on top and the 3 below it. 
// The subtraction operator removes the top two items from the stack, performs 3 − 4, and puts the result of −1 onto the stack. 


/*
	You must create a program with these constraints:

	• The program name is RPN.
	• Your program must take an inverted Polish mathematical expression as an argument.
	• The numbers used in this operation and passed as arguments will always be less than 10. 
		The calculation itself but also the result do not take into account this rule.
	• Your program must process this expression and output the correct result on the standard output.
	• If an error occurs during the execution of the program an error message should be displayed on the standard error.
	• Your program must be able to handle operations with these tokens: "+ - / *".
	
	You must use at least one container in your code to validate this exercise.	
	
	You don’t need to handle brackets or decimal numbers.
	
	Here is an example of standard usage:
	$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	42
	$> ./RPN "7 7 * 7 -"
	42
	$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
	0
	$> ./RPN "(1 + 1)"
	Error
	$>
*/

#include "RPN.hpp"


// bool check_input(std::string input)
// {
// 	std::string::iterator it = input.begin();
// 	while (it != input.end())
// 	{
// 		if (*it == ' ')
// 		{
// 			it++;
// 		}


// 	}


// 	return (true);
// }

bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

bool check_input(std::string split_input)
{
	std::cout << YELLOW << "split input : "<< split_input << DEFAULT << std::endl; // TAKE OUT
	std::cout << YELLOW << "split length : "<< split_input.length() << DEFAULT << std::endl; // TAKE OUT

	if (split_input.length() > 1)
	{
		return (false);
	}
	char c = split_input[0];
	if (!isdigit(c) && !is_operator(c))
	{
		return (false);
	}
	return (true);
}

std::string parse_input(std::string input)
{
	std::cout << BLUE << "not parsed input : "<< input << DEFAULT << std::endl; // TAKE OUT

	// SPLIT
	std::string result;
	std::string split_str;
	char delimiter = ' ';

	auto start_pos = 0;
	auto del_pos = input.find(delimiter, start_pos);

	while (del_pos != std::string::npos) 
	{
		split_str = input.substr(start_pos, del_pos);
		if (!check_input(split_str))
		{
			throw std::invalid_argument("Error");
		}
		else
		{
			result += split_str;
			start_pos = del_pos;
			del_pos = input.find(delimiter, start_pos);
		}
	}

	std::cout << BLUE << "parsed input : "<< result << DEFAULT << std::endl; // TAKE OUT
	return (result);
}

void RPN(std::string input)
{
	
	// std::stack<int> rpn_stack;
	// int total;
	// int stack_items = 0;
	// char symbol;

	try
	{
		parse_input(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	
}

