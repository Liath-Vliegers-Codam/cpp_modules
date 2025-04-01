/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 16:38:53 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 16:38:53 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(std::string type);
		Weapon(void);
		const std::string &getType(void);
		void setType(std::string new_type);
};

#endif
