
#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <string>

#define DEFAULT 					"\033[0m"
#define BOLD    					"\033[1m"
#define RED     					"\033[31m"
#define GREEN   					"\033[32m"
#define YELLOW  					"\033[33m"
#define BLUE    					"\033[34m"
#define MAGENTA 					"\033[35m"
#define CYAN    					"\033[36m"
#define WHITE   					"\033[37m"


#define MAX_CONTACTS 				8

#define WHITESPACES 				"\t\v\n\f\r"
#define NUMBERS 					"0123456789"
#define ALPHABET 					"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

#define ERR_MSG_INPUT_NAME_LENGTH	"The name cannot be more than 26 characters"
#define ERR_MSG_INPUT_NAME_DATA		"The name can only contain characters A - Z and a - z"
#define ERR_MSG_INPUT_NBR_LENGTH	"The number can not be more than 26 digits"
#define ERR_MSG_INPUT_NBR_DATA		"The number can only contain characters 0 - 9"
#define ERR_MSG_INPUT_SECRET_LENGTH	"The secret can not be more than 69 characters"
#define ERR_MSG_INPUT_SECRET_DATA	"Please do not use whitespaces (except space)"
#define ERR_MSG_INPUT_INDEX			"The index should be a single digit"

// #define PROMT_FIRSTNAME	"first name	: "
// #define PROMT_LASTNAME	"last name	: "
// #define PROMT_NICK NAME	"nick name	: "
// #define PROMT_NUMBER	"phone number	: "
// #define PROMT_SECRET	"darkest secret	: "

// #define ERR_MSG_NAME "no whitespaces! >:| "
// #define ERR_MSG_NUMBER "only numbers! >:| "

class Contact
{
	
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
	
	public :
		std::string user_input_names(std::string prompt);
		std::string user_input_number(std::string prompt);
		std::string user_input_secret(std::string prompt);

		void set_first_name(std::string input)
		{
			first_name = input;
		}
		void set_last_name(std::string input)
		{
			last_name = input;
		}
		void set_nick_name(std::string input)
		{
			nick_name = input;
		}
		void set_phone_number(std::string input)
		{
			phone_number = input;
		}
		void set_darkest_sectret(std::string input)
		{
			darkest_secret = input;
		}

		std::string get_first_name(void)
		{
			return (first_name);
		}
		std::string get_last_name(void)
		{
			return (last_name);
		}
		std::string get_nick_name(void)
		{
			return (nick_name);
		}
		std::string get_phone_number(void)
		{
			return (phone_number);
		}
		std::string get_darkest_sectret(void)
		{
			return (darkest_secret);
		}
		std::string search_menu_resize(std::string info)
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
};

class PhoneBook
{
	Contact		contact[MAX_CONTACTS];
	
	public :
		void add_new_contact(int index);
		void search_contacts(int amount_contacts);
		void print_contact_information(int index);

};
