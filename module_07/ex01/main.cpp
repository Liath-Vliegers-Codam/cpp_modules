/*
	Exercise 01 		: Iter
	Turn-in directory	: ex01/
	Files to turn in	: Makefile, main.cpp, iter.{h, hpp}
	Forbidden functions	: None

	Implement a function template iter that takes 3 parameters and returns nothing.
	• The first parameter is the address of an array.
	• The second one is the length of the array.
	• The third one is a function that will be called on every element of the array.

	Submit a main.cpp file that contains your tests. 
	Provide enough code to generate a test executable.

	Your iter function template must work with any type of array. 
	The third parameter can be an instantiated function template.

	The function passed as the third parameter may take its argument by const reference or non-const reference, depending on the context.

	Think carefully about how to support both const and non-const elements in your iter function.
*/

#include "iter.hpp"

int main()
{
	std::string array_str[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	int length_arr_str = length_array(array_str);
	
	iter(array_str, length_arr_str, print_array<std::string>);
	std::cout << std::endl;
	
	iter(array_str, length_arr_str, add_explenation_mark<std::string>);

	iter(array_str, length_arr_str, print_array<std::string>);
	std::cout << std::endl;

	int	array_int[] = {-1, 1, 10, 100, 1000};
	int length_arr_int = length_array(array_int);

	iter(array_int, length_arr_int, print_array<int>);
	std::cout << std::endl;

	iter(array_int, length_arr_int, increment_array<int>);

	iter(array_int, length_arr_int, print_array<int>);
	std::cout << std::endl;
}


