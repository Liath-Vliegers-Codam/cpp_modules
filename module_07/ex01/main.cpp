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
	std::cout << BLUE << "\nINT ARRAY:" << DEFAULT << std::endl;
	int	array_int[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length_arr_int = sizeof(array_int) / sizeof(array_int[0]);

	iter(array_int, length_arr_int, print_array<int>);
	std::cout << std::endl;
	iter(array_int, length_arr_int, increment_array<int>);
	iter(array_int, length_arr_int, print_array<int>);
	std::cout << std::endl;

	std::cout << BLUE << "\nFLOAT ARRAY:" << DEFAULT << std::endl;
	float array_float[] = {1.5f, 2.5f, 3.5f, 4.5f, 5.5f, 6.5f, 7.5f, 8.5f, 9.5f, 10.5f};
	int length_arr_float = sizeof(array_float) / sizeof(array_float[0]);

	iter(array_float, length_arr_float, print_array<float>);
	std::cout << std::endl;
	iter(array_float, length_arr_float, increment_array<float>);
	iter(array_float, length_arr_float, print_array<float>);
	std::cout << std::endl;

	std::cout << BLUE << "\nDOUBLE ARRAY:" << DEFAULT << std::endl;
	double array_double[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
	int length_arr_double = sizeof(array_double) / sizeof(array_double[0]);

	iter(array_double, length_arr_double, print_array<double>);
	std::cout << std::endl;
	iter(array_double, length_arr_double, increment_array<double>);
	iter(array_double, length_arr_double, print_array<double>);
	std::cout << std::endl;

	std::cout << BLUE << "\nCHAR ARRAY:" << DEFAULT << std::endl;
	char array_char[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int length_arr_char = sizeof(array_char) / sizeof(array_char[0]);

	iter(array_char, length_arr_char, print_array<char>);
	std::cout << std::endl;
	iter(array_char, length_arr_char, increment_array<char>);
	iter(array_char, length_arr_char, print_array<char>);
	std::cout << std::endl;

	std::cout << BLUE << "\nSTRING ARRAY:" << DEFAULT << std::endl;
	std::string array_str[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	int length_arr_str = sizeof(array_str) / sizeof(array_str[0]);
	
	iter(array_str, length_arr_str, print_array<std::string>);
	std::cout << std::endl;
	iter(array_str, length_arr_str, add_explenation_mark<std::string>);
	iter(array_str, length_arr_str, print_array<std::string>);
	std::cout << std::endl;


	// // CHANGE THE VALUE IN THE INCREMENT ARRAY FUNCTION TO SOMETHING PRINTABLE

	// iter(array_str, length_arr_str, increment_array<std::string>);
	// iter(array_str, length_arr_str, print_array<std::string>);
	// std::cout << std::endl;

	return (0);
}
