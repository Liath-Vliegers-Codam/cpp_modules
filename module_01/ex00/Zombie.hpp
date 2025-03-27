/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:24 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/27 18:42:00 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <cstdlib>
#include <iostream>
// #include <iomanip> 
#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		void announce(void)
		{
			std::cout << name << ": " << "BraiiiiiiinnnzzzZ...";
		}
};


