/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:43:23 by irozhkov          #+#    #+#             */
/*   Updated: 2024/07/12 19:07:46 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	my_awsome_phonebook;
	std::string	command;

	message_welcome();
	while (command != "EXIT")
	{
		std::cout << GREEN << "Enter your command: " << RESET;
		if (!std::getline(std::cin, command))
		{
			if (std::cin.eof())
			{
				std::cout << RED << "WARNING: End of input" << RESET << std::endl;
				return (1);
			}
			else
			{
				std::cerr << RED << "ERROR ocured" << RESET << std::endl;
				return (1);
			}
		}
		std::cout << std::endl;
		if (command == "ADD")
			my_awsome_phonebook.add();
		else if (command == "SEARCH")
			my_awsome_phonebook.search();
		else if (command != "ADD" && command != "SEARCH" && command != "EXIT")
			std::cout << YELLOW << "WARNING: wrong command" << RESET << std::endl;
	}
	message_bye();
	return (0);
}
