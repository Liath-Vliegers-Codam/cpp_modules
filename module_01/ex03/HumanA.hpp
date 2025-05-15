/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 16:38:20 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 16:38:20 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "./Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		Weapon 		&weapon_of_choice;
		std::string name;

	public:
		HumanA(std::string name, Weapon &weapon);
		void attack();
};

#endif
