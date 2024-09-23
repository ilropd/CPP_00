/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:17 by irozhkov          #+#    #+#             */
/*   Updated: 2024/07/12 19:09:15 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message.hpp"

void	message_welcome(void)
{
	std::cout << GREEN << "Welcome to My Awsome PhoneBook! ";
	std::cout << "Here you can keep up to 8 contacts." << std::endl;
	std::cout << "Use ";
	std::cout << YELLOW << "ADD";
	std::cout << GREEN << " to create new contact, ";
	std::cout << YELLOW << "SEARCH";
	std::cout << GREEN << " to find one and ";
	std::cout << YELLOW << "EXIT";
	std::cout << GREEN << " to quit your phonebook." << RESET << std::endl;
	std::cout << std::endl;
}

void	message_bye(void)
{
	std::cout << YELLOW << "Hope you had fun! See ya soon!" << RESET << std::endl;
	std::cout << std::endl;
}

void	message_full(void)
{
	std::cout << YELLOW << "My Awsome PhoneBook is full!" << std::endl;
	std::cout << "Next contact you add will destroy the oldest one! ";
	std::cout << "This is the final warning!" << RESET << std::endl;
	std::cout << std::endl;
}
