
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
		std::cout << "name of Data in struct_array at index 0 = " << struct_array[0].name << " and id = " << struct_array[0].id << std::endl;
		std::cout << "name of Data in struct_array at index 1 = " << struct_array[1].name << " and id = " << struct_array[1].id << std::endl;
		std::cout << "name of Data in struct_array at index 4 = " << struct_array[4].name << " and id = " << struct_array[4].id << std::endl;
		std::cout << "name of Data in struct_array at index 7 = " << struct_array[7].name << " and id = " << struct_array[7].id << std::endl;
		std::cout << "name of Data in struct_array at index 10 = " << struct_array[10].name << " and id = " << struct_array[10].id << std::endl;
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

void copy_and_assignment_tests(void)
{
	std::cout << GREEN << "TEST: copy and assignment tests" << DEFAULT << std::endl;

	Array<int> arr(5);
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] = static_cast<int>(i * 10);
	}

	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << "arr index "<< i << " = " << arr[i] << std::endl;
	}
	
	std::cout << MAGENTA << "\nCreating copy of arr using copy constructor" << DEFAULT << std::endl;
	Array<int> copy = arr;
	for (size_t i = 0; i < copy.size(); i++)
	{
		std::cout << "copy index "<< i << " = " << copy[i] << std::endl;
	}

	std::cout << MAGENTA << "modifying copy and arr to check for deep copy" << DEFAULT << std::endl;

	std::cout << MAGENTA << "set arr[0] = 42" << DEFAULT << std::endl;
	arr[0] = 42;
	std::cout << "copy[0] = " << copy[0] << std::endl;
	std::cout << "arr[0] = " << arr[0] << std::endl;

	std::cout << MAGENTA << "set copy[1] = 777" << DEFAULT << std::endl;
	copy[1] = 777;
	std::cout << "copy[1] = " << copy[1] << std::endl;
	std::cout << "arr[1] = " << arr[1] << std::endl;

	std::cout << MAGENTA << "\nCreating assigned array using assignment operator" << DEFAULT << std::endl;
	Array<int> assigned;
	assigned = arr;
	for (size_t i = 0; i < assigned.size(); i++)
	{
		std::cout << "assigned index "<< i << " = " << assigned[i] << std::endl;
	}
	std::cout << MAGENTA << "set arr[1] = 444" << DEFAULT << std::endl;
	arr[1] = 444;
	std::cout << "assigned[0] = " << assigned[0] << std::endl;
	std::cout << "assigned[1] = " << assigned[1] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl;
	std::cout << "copy[1] = " << copy[1] << std::endl;
	std::cout << "arr[0] = " << arr[0] << std::endl;
	std::cout << "arr[1] = " << arr[1] << std::endl;
}


int main(void)
{
	subject_tests();

	copy_and_assignment_tests();

	int_array_tests();

	float_and_double_tests();

	string_array_tests();

	struct_array_tests();

	array_array_tests();

	return (0);
}
