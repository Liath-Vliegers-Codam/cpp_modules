/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 16:38:41 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 16:38:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "./Weapon.hpp"

class HumanB
{
	private:
		Weapon		*weapon_of_choice;
		std::string name;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void);
};

#endif
