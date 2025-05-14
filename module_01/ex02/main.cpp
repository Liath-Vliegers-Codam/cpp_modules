/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/31 16:31:22 by anonymous     #+#    #+#                 */
/*   Updated: 2025/03/31 16:31:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// inplaats van the value kopieren we het adress in een reference
// references are stored on the stack. pointers often on the heap.
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable:	" << &str << std::endl;
	std::cout << "The memory address held by stringPTR:		" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:		" << &stringREF << std::endl;

	std::cout << "The value of the string variable:		" << str << std::endl;
	std::cout << "The value pointed to by stringPTR:		" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:		" << stringREF << std::endl;

	return (0);
}

// *stringPTR = "bliep";
// std::cout << str << std::endl;
// stringREF = "miep";
// std::cout << str << std::endl;
