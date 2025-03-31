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

/*

Exercise : 02
HI THIS IS BRAIN

Turn-in directory	: ex02/
Files to turn in	: Makefile, main.cpp
Forbidden functions : None

Write a program that contains:
	• A string variable initialized to "HI THIS IS BRAIN".
	• stringPTR: a pointer to the string.
	• stringREF: a reference to the string.
Your program must print:
	• The memory address of the string variable.
	• The memory address held by stringPTR.
	• The memory address held by stringREF.
And then:
	• The value of the string variable.
	• The value pointed to by stringPTR.
	• The value pointed to by stringREF.
That’s all—no tricks. The goal of this exercise is to demystify references, which may seem completely new. 
Although there are some small differences, this is simply another syntax for something you already do: address manipulation.

*/

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
