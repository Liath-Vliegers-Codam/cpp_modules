
#include "phonebook.hpp"

// find_first_not_of("0123456789")
// If no such characters are found, the function returns string::npos.

// find_first_of("0123456789")
// If no matches are found, the function returns string::npos.

std::string Contact::user_input_names(std::string prompt)
{
	// only a - Z characters , 26 chars length
	std::string input;

	while (1)
	{
		std::cout << GREEN << prompt << DEFAULT;
		if (!std::getline(std::cin, input))
		{
			std::exit(1);
		}
		if (input.length() < 1)
		{
			continue;
		}
		if (input.length() > 26)
		{
			std::cout << ERR_MSG_INPUT_NAME_LENGTH << std::endl;
			continue;
		}
		if (input.find_first_not_of(ALPHABET) != std::string::npos)
		{
			std::cout << ERR_MSG_INPUT_NAME_DATA << std::endl;
			continue;
		}
		else
		{
			return (input);
		}
	}
}

std::string Contact::user_input_number(std::string prompt)
{
	// only 0-9, 26 chars
	std::string input;

	while (1)
	{
		std::cout << GREEN << prompt << DEFAULT;
		if (!std::getline(std::cin, input))
		{
			std::exit(1);
		}
		if (input.length() < 1)
		{
			continue;
		}
		if (input.length() > 26)
		{
			std::cout << ERR_MSG_INPUT_NBR_LENGTH << std::endl;
			continue;
		}
		if (input.find_first_not_of(NUMBERS) != std::string::npos)
		{
			std::cout << ERR_MSG_INPUT_NBR_DATA << std::endl;
			continue;
		}
		else
		{
			return (input);
		}
	}
}

std::string Contact::user_input_secret(std::string prompt)
{
	// no weird whitespaces, no longer than 69 chars
	std::string input;

	while (1)
	{
		std::cout << GREEN << prompt << DEFAULT;
		if (!std::getline(std::cin, input))
		{
			std::exit(1);
		}
		if (input.length() < 1)
		{
			continue;
		}
		if (input.length() > 69)
		{
			std::cout << ERR_MSG_INPUT_SECRET_LENGTH << std::endl;
			continue;
		}
		if (input.find_first_of(WHITESPACES) != std::string::npos)
		{
			std::cout << ERR_MSG_INPUT_SECRET_DATA << std::endl;
			continue;
		}
		else
		{
			return (input);
		}
	}
}


void	PhoneBook::add_new_contact(int index)
{
	Contact	new_contact;

	std::cout << GREEN << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|            ADDING NEW CONTACT             |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << DEFAULT << std::endl;

	new_contact.set_first_name(new_contact.user_input_names("first name	: "));
	new_contact.set_last_name(new_contact.user_input_names("last name	: "));
	new_contact.set_nick_name(new_contact.user_input_names("nick name	: "));
	new_contact.set_phone_number(new_contact.user_input_number("phone number	: "));
	new_contact.set_darkest_sectret(new_contact.user_input_secret("darkest secret	: "));

	std::cout << GREEN << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|        ADDED ";
	std::cout << DEFAULT << std::setw(10) << new_contact.search_menu_resize(new_contact.get_first_name()) << GREEN;
	std::cout << " TO CONTACTS       |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	// std::cout << "     ADDED "  << DEFAULT << new_contact.get_first_name() << GREEN <<  " TO CONTACTS|" << "(on index " << index << ")" << std::endl;
	std::cout << DEFAULT;

	contact[index] = new_contact;
}



void	PhoneBook::print_contact_information(int i)
{
	int index;

	index = i - 1;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "             CONTACT INFORMATION             " << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	
	std::cout << "|first name	: " << std::setw(26) << contact[index].get_first_name() << "|" << std::endl;
	std::cout << "|last name	: " << std::setw(26) << contact[index].get_last_name() << "|" << std::endl;
	std::cout << "|nick name	: " << std::setw(26) << contact[index].get_nick_name() << "|" << std::endl;
	std::cout << "|phone number	: " << std::setw(26) << contact[index].get_phone_number() << "|" << std::endl;

	std::string secret_line;
	std::string secret_line_one;
	std::string secret_line_two;

	secret_line = contact[index].get_darkest_sectret();

	if (secret_line.length() > 26)
	{
		secret_line_one = secret_line.substr(0, 26);
		secret_line_two = secret_line.substr(26);
		std::cout << "|darkest secret	: " << std::setw(26) << secret_line_one << "|" << std::endl;
		std::cout << "|" << std::setw(43) << secret_line_one << "|" << std::endl;
	}
	else
	{
		std::cout << "|darkest secret	: " << std::setw(26) << secret_line << "|" << std::endl;
	}

	std::cout << DEFAULT;
}

void	PhoneBook::search_contacts(int amount_contacts)
{
	std::string user_input_index;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|              SEARCH CONTACTS              |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|   index  |first name| last name| nick name|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < amount_contacts; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << contact[i].search_menu_resize(contact[i].get_first_name());
		std::cout << "|" << std::setw(10) << contact[i].search_menu_resize(contact[i].get_last_name());
		std::cout << "|" << std::setw(10) << contact[i].search_menu_resize(contact[i].get_nick_name());
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|    please enter the index of a contact    |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	while (1)
	{
		std::cout << GREEN << "index : " << DEFAULT;
		if (!std::getline(std::cin, user_input_index))
		{
			std::exit(1);
		}
		if (user_input_index.length() < 1)
		{
			continue;
		}
		if (user_input_index.find_first_of(NUMBERS) == std::string::npos || user_input_index.length() > 1)
		{
			std::cout << ERR_MSG_INPUT_INDEX << std::endl;
			continue;
		}
		else
		{
			print_contact_information(user_input_index[0] - '0');
			break;
		}
	}
}




void print_menu()
{
	std::cout << YELLOW << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|                 HOME PAGE                 |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "| please enter one of the following options:|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|         " << GREEN << "ADD" << YELLOW << "|";
	std::cout << "         " << BLUE << "SEARCH" << YELLOW << "|";
	std::cout << "          " << RED << "EXIT" << YELLOW << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << DEFAULT << std::endl;
}

int main(void)
{
	PhoneBook	phonebook;
	int 		index;
	bool		max_contacts;
	std::string	user_input;

	index = 0;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     WELCOME TO THE ULTIMATE PHONEBOOK!    |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (1)
	{
		print_menu();
		if (!std::getline(std::cin, user_input))
		{
			std::exit(1);
		}
		if (user_input == "ADD")
		{
			if (index == MAX_CONTACTS)
			{
				index = 0;
				max_contacts = true;
			}
			phonebook.add_new_contact(index);
			index++;
		}
		else if (user_input == "SEARCH")
		{
			if (max_contacts == true)
			{
				phonebook.search_contacts(MAX_CONTACTS);
			}
			else
			{
				phonebook.search_contacts(index);
			}
		}
		else if (user_input == "EXIT")
		{
			std::cout << RED << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << "             EXITING PHONEBOOK...            " << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << DEFAULT << std::endl;
			std::exit(0); // or return 0 ? user_input probably needs to be freed
		}
		else
		{
			continue;
		}
	}
	
}