/*
	Exercise 02 		: Array
	Turn-in directory	: ex02/
	Files to turn in	: Makefile, main.cpp, Array.{h, hpp}, and optional file	: Array.tpp
	Forbidden functions	: None

	Develop a class template Array that contains elements of type T and that implements the following behavior and functions:

	• Construction with no parameter: Creates an empty array.
	• Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
		Tip: Try to compile int * a = new int(); then display *a.
	• Construction by copy and assignment operator. 
		In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
	• You MUST use the operator new[] to allocate memory. 
		Preventive allocation (allocating memory in advance) is forbidden. 
		Your program must never access non-allocated memory.
	• Elements can be accessed through the subscript operator: [ ].
	• When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
	• A member function size() that returns the number of elements in the array. 
		This member function takes no parameters and must not modify the current instance.

	As usual, ensure everything works as expected and turn in a main.cpp file that contains your tests.
*/

#include "Array.hpp"

void subject_tests(void)
{
	std::cout << GREEN << "TEST: Subject test: default int" << DEFAULT << std::endl;
	int* a = new int();
	std::cout << "value pointed to by a: " << *a << std::endl;
	delete a;

	int* b = new int(10);
	std::cout  << "value pointed to by b: " << *b << std::endl;
	delete b;

	int* c = new int(10000);
	std::cout  << "value pointed to by c: " << *c << std::endl;
	delete c;
}

void int_array_tests(void)
{
	std::cout << GREEN << "TEST: default constructed INT array" << DEFAULT << std::endl;

	Array<int> int_array_empty;
	std::cout << "int_array_empty size = " << int_array_empty.size() << std::endl;
	try
	{
		std::cout << "int_array_empty value on index 0 = " << int_array_empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << GREEN << "TEST: parameterized constructed INT array" << DEFAULT << std::endl;

	Array<int> int_array(10);
	std::cout << "int_array size = "<< int_array.size() << std::endl;
	for (size_t i = 0; i < int_array.size(); i++)
	{
		int_array[i] = 42;
	}
	for (size_t i = 0; i < int_array.size(); i++)
	{
		std::cout << "int_array index "<< i << " = " << int_array[i] << std::endl;
	}
}

void float_and_double_tests(void)
{
	std::cout << GREEN << "TEST: default constructed float array" << DEFAULT << std::endl;

	Array<float> float_array_empty;
	std::cout << "float_array_empty size = " << float_array_empty.size() << std::endl;
	try
	{
		std::cout << "float_array_empty value on index 0 = " << float_array_empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << GREEN << "TEST: parameterized constructed float array" << DEFAULT << std::endl;

	Array<float> float_array(10);
	std::cout << "float_array size = "<< float_array.size() << std::endl;
	for (size_t i = 0; i < float_array.size(); i++)
	{
		float_array[i] = 42.42f;
	}
	for (size_t i = 0; i < float_array.size(); i++)
	{
		std::cout << "float_array index "<< i << " = " << float_array[i] << std::endl;
	}

	std::cout << GREEN << "TEST: default constructed double array" << DEFAULT << std::endl;

	Array<double> double_array_empty;
	std::cout << "double_array_empty size = " << double_array_empty.size() << std::endl;
	try
	{
		std::cout << "double_array_empty value on index 0 = " << double_array_empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << GREEN << "TEST: parameterized constructed double array" << DEFAULT << std::endl;

	Array<double> double_array(10);
	std::cout << "double_array size = "<< double_array.size() << std::endl;
	for (size_t i = 0; i < double_array.size(); i++)
	{
		double_array[i] = 42.42;
	}
	for (size_t i = 0; i < double_array.size(); i++)
	{
		std::cout << "double_array index "<< i << " = " << double_array[i] << std::endl;
	}
}

void string_array_tests(void)
{
	std::cout << GREEN << "TEST: default constructed STRING array" << DEFAULT << std::endl;

	Array<std::string> string_array_empty;
	std::cout << "string_array_empty size = " << string_array_empty.size() << std::endl;
	try
	{
		std::cout << "string_array_empty value on index 0 = " << string_array_empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << GREEN << "TEST: parameterized constructed STRING array" << DEFAULT << std::endl;

	Array<std::string>string_array(10);
	std::cout << "string_array size = "<< string_array.size() << std::endl;
	for (size_t i = 0; i < string_array.size(); i++)
	{
		if (i % 2 == 0)
			string_array[i] = "hello!";
		else
			string_array[i] = "bye!";
	}
	for (size_t i = 0; i < string_array.size(); i++)
	{
		std::cout << "string_array index "<< i << " = " << string_array[i] << std::endl;
	}

	try
	{
		std::cout << "value of string_array at index 0 = " << string_array[0] << std::endl;
		std::cout << "value of string_array at index 1 = " << string_array[1] << std::endl;
		std::cout << "value of string_array at index 4 = " << string_array[4] << std::endl;
		std::cout << "value of string_array at index 7 = " << string_array[7] << std::endl;
		std::cout << "value of string_array at index 10 = " << string_array[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
}

void struct_array_tests(void)
{
	struct Data
	{
		int			id;
		std::string name;
	};

	std::cout << GREEN << "TEST: default constructed STRUCT array" << DEFAULT << std::endl;
	Array<Data> struct_array_empty;
	std::cout << "struct_array_empty size = " << struct_array_empty.size() << std::endl;
	try
	{
		std::cout << "struct_array_empty data on index 0 = " << struct_array_empty[0].id << " " << struct_array_empty[0].name << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << GREEN << "TEST: parameterized constructed STRUCT array" << DEFAULT << std::endl;
	Array<Data> struct_array(10);
	std::cout << "struct_array size = "<< struct_array.size() << std::endl;
	for (size_t i = 0; i < struct_array.size(); i++)
	{
		struct_array[i].id = i;
		struct_array[i].name = "name_" + std::to_string(i);
	}
	for (size_t i = 0; i < struct_array.size(); i++)
	{
		std::cout << "struct_array index "<< i << " = " << struct_array[i].id << " " << struct_array[i].name << std::endl;
	}

	try
	{
		std::cout << "name of Data in struct_array at index 0 = " << struct_array[0].name << std::endl;
		std::cout << "name of Data in struct_array at index 1 = " << struct_array[1].name << std::endl;
		std::cout << "name of Data in struct_array at index 4 = " << struct_array[4].name << std::endl;
		std::cout << "name of Data in struct_array at index 7 = " << struct_array[7].name << std::endl;
		std::cout << "name of Data in struct_array at index 10 = " << struct_array[10].name << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
}

void array_array_tests(void)
{
	std::cout << GREEN << "TEST: default constructed ARRAY array" << DEFAULT << std::endl;

	Array<Array<int>> array_array_empty;
	std::cout << "array_array_empty size = " << array_array_empty.size() << std::endl;
	try
	{
		std::cout << "array_array_empty value on index 0 0 = " << array_array_empty[0][0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << GREEN << "TEST: parameterized constructed ARRAY array" << DEFAULT << std::endl;

	Array<Array<int>> array_array(5);
	std::cout << "array_array size = "<< array_array.size() << std::endl;
	for (size_t i = 0; i < array_array.size(); i++)
	{
		array_array[i] = Array<int>(5);
		for (size_t j = 0; j < array_array[i].size(); j++)
		{
			array_array[i][j] = i * 10 + j;
		}
	}
	for (size_t i = 0; i < array_array.size(); i++)
	{
		for (size_t j = 0; j < array_array[i].size(); j++)
		{
			std::cout << "array_array index "<< i <<" "<< j <<" = " << array_array[i][j] << std::endl;
		}
	}

	try
	{
		std::cout << "value of array_array at index 0 0 = " << array_array[0][0] << std::endl;
		std::cout << "value of array_array at index 1 2 = " << array_array[1][2] << std::endl;
		std::cout << "value of array_array at index 3 4 = " << array_array[3][4] << std::endl;
		std::cout << "value of array_array at index 4 4 = " << array_array[4][4] << std::endl;
		std::cout << "value of array_array at index 5 0 = " << array_array[5][0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

}



// TODO find jisses edge case

int main(void)
{
	subject_tests();

	int_array_tests();

	float_and_double_tests();

	string_array_tests();

	struct_array_tests();

	array_array_tests();

	return (0);
}
