/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 18:33:32 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/27 18:33:32 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <cstring>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else
	{
		std::string str;
		int i = 1;

		while (argv[i] != NULL)
		{
			str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
			{
				char ch = std::toupper(str[j]);
				std::cout << ch;
			}
			i++;
		}
		std::cout << "\n";
	}
	return (0);
}
