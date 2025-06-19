
#include <iostream>

// str heeft een eigen adress
// pointer heeft een eigen adress maar points to het adress van str
// ref copys adress van str

int main(void)
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
