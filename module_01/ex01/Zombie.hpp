/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:24 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/01 16:38:08 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_H
#define ZOMBIE_H


#include <iostream>

class Zombie
{
	private:
	std::string name;

	public:
		void announce(void);
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif