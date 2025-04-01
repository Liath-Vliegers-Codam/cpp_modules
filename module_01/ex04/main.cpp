/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:24:58 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 18:24:58 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
## Chapter VII Exercise 04: Sed is for losers

Exercise 04			: Sed is for losers
Turn-in directory 	: ex04/
Files to turn in 	: 	- Makefile
						- main.cpp
						- *.cpp
						- *.{h, hpp}
Forbidden functions : std::string::replace

Create a program that takes three parameters in the following order: a filename and two strings, s1 and s2.

It must open the file <filename> and copy its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.  
Using C file manipulation functions is forbidden and will be considered cheating. 
All the member functions of the class std::string are allowed, except replace. Use them wisely!  
Of course, handle unexpected inputs and errors. 
You must create and turn in your own tests to ensure that your program works as expected.
*/

#include <iostream>
#include <fstream>

std::string replace_s1_with_s2(std::string line, std::string s1, std::string s2)
{
	(void)s2;
	size_t position;

	position = line.find(s1, 0);
	while (position != std::string::npos)
	{
		std::cout << "we found " << s1 << "!" << std::endl;
		line.erase(position, s1.length());
		line.insert(position, s2);

		position = line.find(s1, position + s1.length());
	}
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "This program takes three parameters in the following order: a filename and two strings, s1 and s2." << std::endl;
		return (1);
	}
	
	std::string og_file_name = argv[1];
	std::string rep_file_name = og_file_name + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];
		
	std::string line;

	std::ifstream original_file(og_file_name);
	std::ofstream replace_file(rep_file_name);

	if (original_file.is_open() && replace_file.is_open())
	{
		while (std::getline(original_file, line))
		{
			line = replace_s1_with_s2(line, s1, s2);
			replace_file << line;
		}
		original_file.close();
		replace_file.close();
	}
	else
	{
		std::cout << "Error: could not open file" << std::endl;
	}
	return (0);
}
