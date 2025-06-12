/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 19:19:26 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 19:19:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int main(void)
{
	Harl harl;

	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("ERROR");
}
