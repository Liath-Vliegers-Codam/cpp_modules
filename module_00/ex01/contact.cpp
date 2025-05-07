/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 16:13:55 by livliege      #+#    #+#                 */
/*   Updated: 2025/05/07 16:37:57 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::set_first_name(std::string input)
{
	_first_name = input;
}
void Contact::set_last_name(std::string input)
{
	_last_name = input;
}
void Contact::set_nick_name(std::string input)
{
	_nick_name = input;
}
void Contact::set_phone_number(std::string input)
{
	_phone_number = input;
}
void Contact::set_darkest_sectret(std::string input)
{
	_darkest_secret = input;
}
std::string Contact::get_first_name(void)
{
	return (_first_name);
}
std::string Contact::get_last_name(void)
{
	return (_last_name);
}
std::string Contact::get_nick_name(void)
{
	return (_nick_name);
}
std::string Contact::get_phone_number(void)
{
	return (_phone_number);
}
std::string Contact::get_darkest_sectret(void)
{
	return (_darkest_secret);
}
std::string Contact::search_menu_resize(std::string info)
{
	size_t len;
	std::string resized_info;
	
	len = info.length();
	if (len <= 10)
	{
		return (info);
	}
	else 
	{
		resized_info = info.substr(0, 9) + ".";
		return (resized_info);
	}
}
std::string Contact::new_contact_resize(std::string name)
{
	size_t len;
	std::string resized_name;
	
	len = name.length();
	if (len <= 10)
	{
		while (len < 10)
		{
			name = name + ' ';
			len++;
		}
		return (name);
	}
	else
		return (search_menu_resize(name));
}
