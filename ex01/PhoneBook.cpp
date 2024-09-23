/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:53:51 by irozhkov          #+#    #+#             */
/*   Updated: 2024/07/12 19:06:05 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"
#include "message.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
	std::string	str;

	str = "";
	if (this->index > 7)
		message_full();
	while (!std::cin.eof() && str == "" )
	{
		std::cout << GREEN << "Enter FIRST NAME: " << RESET;
		if (std::getline(std::cin, str) && str != "" && input_isprint(str))
			this->contacts[this->index % 8].set_first_name(str);
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << GREEN << "Enter LAST NAME: " << RESET;
		if (std::getline(std::cin, str) && str != "" && input_isprint(str))
			this->contacts[this->index % 8].set_last_name(str);
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << GREEN << "Enter NICKNAME: " << RESET;
		if (std::getline(std::cin, str) && str != "" && input_isprint(str))
			this->contacts[this->index % 8].set_nickname(str);
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << GREEN << "Enter PHONE NUMBER: " << RESET;
		if (std::getline(std::cin, str) && str != "" && input_isprint(str)) 
			this->contacts[this->index % 8].set_phone_number(str);
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << GREEN << "Enter DARKEST SECRET: " << RESET;
		if (std::getline(std::cin, str) && str != "" && input_isprint(str))
			this->contacts[this->index % 8].set_darkest_secret(str);
		else
			str = "";
	}
	if (!this->contacts[this->index % 8].get_first_name().empty())
	{
		std::cout << YELLOW << "Contact added!" << RESET << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << RED << "ERROR: contact NOT added" << RESET << std::endl;
		std::cout << std::endl;
		return ;
	}

	this->index++;
}

void	PhoneBook::search(void)
{
	std::string	str;

	if (!search_contact(this->contacts))
	{
		std::cout << YELLOW << "Sorry...";
		std::cout << "My Awesome PhoneBook is empty..." << RESET << std::endl;
		std::cout << std::endl;
		return ;
	}
	str = "";
	while (!std::cin.eof() && str == ""
		   && contacts[str[0] - 1 - '0'].get_first_name().empty())
	{
		std::cout << GREEN << "Enter INDEX of the contact to show: " << RESET;
		if (std::getline(std::cin, str) && str != "")
		{
			std::cout << std::endl;
			if (str.length() == 1 && (str[0] >= '1' && str[0] <= '8')
				&& !contacts[str[0] - 1 - '0'].get_first_name().empty())
			{
				if (!std::cin.eof())
				{
					std::cout << YELLOW << "Here all I have about contact ";
					std::cout << str[0] << RESET << std::endl;
					this->print(this->contacts[str[0] - 1 - '0']);
				}
				else
				{
					std::cout << RED << "ERROR: EOF" << RESET << std::endl;
					std::cout << std::endl;
					return ;
				}
			}
			else
			{
				std::cout << YELLOW << "WARNING: invalid INDEX. Try again!" << RESET << std::endl;
				std::cout << std::endl;
				str = "";
			}
		}
	}
}

void	PhoneBook::print(Contact contacts)
{
	if (contacts.get_first_name().empty())
	{
		std::cout << RED << "ERROR: this contact is empty" << RESET << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << YELLOW << "FIRST NAME:     "<< RESET << contacts.get_first_name() << std::endl;
	std::cout << YELLOW << "LAST NAME:      " << RESET << contacts.get_last_name() << std::endl;
	std::cout << YELLOW << "NICKNAME:       " << RESET << contacts.get_nickname() << std::endl;
	std::cout << YELLOW << "PHONE NUMBER:   " << RESET << contacts.get_phone_number() << std::endl;
	std::cout << YELLOW << "DARKEST SECRET: " << RESET << contacts.get_darkest_secret() << std::endl;
	std::cout << std::endl;
}

Contact PhoneBook::get_contact(int index)
{
	return (this->contacts[index % 8]);
}
