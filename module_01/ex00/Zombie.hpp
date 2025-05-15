/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 18:35:24 by livliege      #+#    #+#                 */
/*   Updated: 2025/05/15 17:23:08 by livliege      ########   odam.nl         */
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
		~Zombie(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
