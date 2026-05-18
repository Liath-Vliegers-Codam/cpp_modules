/*
	Exercise 00 		: Start with a few functions
	Turn-in directory	: ex00/
	Files to turn in	: Makefile, main.cpp, whatever.{h, hpp}
	Forbidden functions	: None

	Implement the following function templates:
	• swap: Swaps the values of two given parameters. 
		returns nothing.
	• min: Compares the two values passed as parameters.
		returns the smallest one, if they are equal, it returns the second one.
	• max: Compares the two values passed as parameters.
		returns the greatest one, if they are equal, it returns the second one.

	These functions can be called with any type of argument. 
	The only requirement is that the two arguments must have the same type and must support all the comparison operators.

	Templates must be defined in the header files.
*/


#include "templates.hpp"
#include "TestClass.hpp"

int main(void)
{
	std::cout << BLUE << "\nINTS:" << DEFAULT << std::endl;
	int int_one = 2;
	int int_two = 3;
	std::cout << "int_one = " << int_one << std::endl;
	std::cout << "int_two = " << int_two << std::endl;
	std::cout << "the minimum value of int_one (" << int_one << ") and int_two (" << int_two << ") = " << ::min(int_one, int_two) << std::endl;
	std::cout << "the maximum value of int_one (" << int_one << ") and int_two (" << int_two << ") = " << ::max(int_one, int_two) << std::endl;
	::swap(int_one, int_two);
	std::cout << MAGENTA << "after swap: " << DEFAULT << std::endl;
	std::cout << "int_one = " << int_one << std::endl;
	std::cout << "int_two = " << int_two << std::endl;

	std::cout << BLUE << "\nFLOATS:" << DEFAULT << std::endl;
	float float_one = 1.5f;
	float float_two = 2.5f;
	std::cout << "float_one = " << float_one << std::endl;
	std::cout << "float_two = " << float_two << std::endl;
	std::cout << "the minimum value of float_one (" << float_one << ") and float_two (" << float_two << ") = " << ::min(float_one, float_two) << std::endl;
	std::cout << "the maximum value of float_one (" << float_one << ") and float_two (" << float_two << ") = " << ::max(float_one, float_two) << std::endl;
	::swap(float_one, float_two);
	std::cout << MAGENTA << "after swap: " << DEFAULT << std::endl;
	std::cout << "float_one = " << float_one << std::endl;
	std::cout << "float_two = " << float_two << std::endl;

	std::cout << BLUE << "\nDOUBLES:" << DEFAULT << std::endl;
	double double_one = 1.5;
	double double_two = 2.5;
	std::cout << "double_one = " << double_one << std::endl;
	std::cout << "double_two = " << double_two << std::endl;	
	std::cout << "the minimum value of double_one (" << double_one << ") and double_two (" << double_two << ") = " << ::min(double_one, double_two) << std::endl;
	std::cout << "the maximum value of double_one (" << double_one << ") and double_two (" << double_two << ") = " << ::max(double_one, double_two) << std::endl;
	::swap(double_one, double_two);
	std::cout << MAGENTA << "after swap: " << DEFAULT << std::endl;
	std::cout << "double_one = " << double_one << std::endl;
	std::cout << "double_two = " << double_two << std::endl;

	std::cout << BLUE << "\nCHARS:" << DEFAULT << std::endl;
	char char_one = 'a';
	char char_two = 'b';
	std::cout << "char_one = " << char_one << std::endl;
	std::cout << "char_two = " << char_two << std::endl;
	std::cout << "the minimum value of char_one (" << char_one << ") and char_two (" << char_two << ") = " << ::min(char_one, char_two) << std::endl;
	std::cout << "the maximum value of char_one (" << char_one << ") and char_two (" << char_two << ") = " << ::max(char_one, char_two) << std::endl;
	::swap(char_one, char_two);
	std::cout << MAGENTA << "after swap: " << DEFAULT << std::endl;
	std::cout << "char_one = " << char_one << std::endl;
	std::cout << "char_two = " << char_two << std::endl;

	std::cout << BLUE << "\nSTRINGS:" << DEFAULT << std::endl;
	std::string string_one = "chaine1";
	std::string string_two = "chaine2";
	std::cout << "string_one = " << string_one << std::endl;
	std::cout << "string_two = " << string_two << std::endl;
	std::cout << "the minimum value of string_one (" << string_one << ") and string_two (" << string_two << ") = " << ::min(string_one, string_two) << std::endl;
	std::cout << "the maximum value of string_one (" << string_one << ") and string_two (" << string_two << ") = " << ::max(string_one, string_two) << std::endl;
	::swap(string_one, string_two);
	std::cout << MAGENTA << "after swap: " << DEFAULT << std::endl;
	std::cout << "string_one = " << string_one << std::endl;
	std::cout << "string_two = " << string_two << std::endl;

	std::cout << BLUE << "\nCLASSES:" << DEFAULT << std::endl;
	TestClass test_class_one(1, 1.5f, 2.5, "test_class_one");
	TestClass test_class_two(2, 2.5f, 3.5, "test_class_two");
	std::cout << "test_class_one:" << std::endl;
	std::cout << test_class_one << std::endl;
	std::cout << "test_class_two:" << std::endl;
	std::cout << test_class_two << std::endl;
	std::cout << "the minimum int value of test_class_one and test_class_two = " << ::min(test_class_one.getInt(), test_class_two.getInt()) << std::endl;
	std::cout << "the maximum int value of test_class_one and test_class_two = " << ::max(test_class_one.getInt(), test_class_two.getInt()) << std::endl;

	std::cout << "the minimum float value of test_class_one and test_class_two = " << ::min(test_class_one.getFloat(), test_class_two.getFloat()) << std::endl;
	std::cout << "the maximum float value of test_class_one and test_class_two = " << ::max(test_class_one.getFloat(), test_class_two.getFloat()) << std::endl;

	std::cout << "the minimum double value of test_class_one and test_class_two = " << ::min(test_class_one.getDouble(), test_class_two.getDouble()) << std::endl;
	std::cout << "the maximum double value of test_class_one and test_class_two = " << ::max(test_class_one.getDouble(), test_class_two.getDouble()) << std::endl;

	std::cout << "the minimum string value of test_class_one and test_class_two = " << ::min(test_class_one.getString(), test_class_two.getString()) << std::endl;
	std::cout << "the maximum string value of test_class_one and test_class_two = " << ::max(test_class_one.getString(), test_class_two.getString()) << std::endl;

	::swap(test_class_one, test_class_two);
	std::cout << MAGENTA << "after swap: " << DEFAULT << std::endl;
	std::cout << "test_class_one:" << std::endl;
	std::cout << test_class_one << std::endl;
	std::cout << "test_class_two:" << std::endl;
	std::cout << test_class_two << std::endl;
	
	return (0);
}
