/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/02 18:32:52 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/27 18:32:52 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

// #include <cstdlib>
#include <iostream>
#include <iomanip> 
// #include <string>

#define DEFAULT 					"\033[0m"
#define BOLD    					"\033[1m"
#define RED     					"\033[31m"
#define GREEN   					"\033[32m"
#define YELLOW  					"\033[33m"
#define BLUE    					"\033[34m"
#define LIGHT_BLUE					"\033[94m"
#define MAGENTA 					"\033[35m"
#define CYAN    					"\033[36m"
#define WHITE   					"\033[37m"

#define MAX_CONTACTS 				8

#define WHITESPACES 				"\t\v\n\f\r"
#define NUMBERS 					"0123456789"
#define ALPHABET 					"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

#define ERR_MSG_INPUT_NAME_LENGTH	"The name can't be more than 26 characters"
#define ERR_MSG_INPUT_NAME_DATA		"The name can only contain characters A - Z and a - z"
#define ERR_MSG_INPUT_NBR_LENGTH	"The number can not be more than 26 digits"
#define ERR_MSG_INPUT_NBR_DATA		"The number can only contain characters 0 - 9"
#define ERR_MSG_INPUT_SECRET_LENGTH	"The secret can not be more than 69 characters"
#define ERR_MSG_INPUT_SECRET_DATA	"Please do not use whitespaces (except space)"
#define ERR_MSG_INPUT_INDEX			"The index should be a single positive digit"
#define ERR_MSG_INPUT_INDEX_MAX		"The Phonebook does not contain that many contacts."

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
	
	public :
		std::string user_input_names(std::string prompt);
		std::string user_input_number(std::string prompt);
		std::string user_input_secret(std::string prompt);
		void set_first_name(std::string input);
		void set_last_name(std::string input);
		void set_nick_name(std::string input);
		void set_phone_number(std::string input);
		void set_darkest_sectret(std::string input);
		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nick_name(void);
		std::string get_phone_number(void);
		std::string get_darkest_sectret(void);
		std::string search_menu_resize(std::string info);
		std::string new_contact_resize(std::string name);
};

class PhoneBook
{
	private:
		Contact		_contacts[MAX_CONTACTS];
	
	public :
		void add_new_contact(int index);
		void search_contacts(int amount_contacts);
		void print_contact_information(int index);
};

#endif
