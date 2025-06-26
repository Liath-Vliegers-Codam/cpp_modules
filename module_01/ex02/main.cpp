
#include <iostream>

// str has a memory address
// stringPTR is a pointer that holds the address of str
// stringREF is a reference that refers to str
// pointer has its own address but points to the address of str
// ref copies the address of str
// reference is an alias for a variable
// pointer is a variable that holds the address of another variable

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable:	" << &str << std::endl;
	std::cout << "The memory address held by stringPTR:		" << &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:		" << &stringREF << std::endl;

	std::cout << "The value of the string variable:		" << str << std::endl;
	std::cout << "The value pointed to by stringPTR:		" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:		" << stringREF << std::endl;

	return (0);
}
