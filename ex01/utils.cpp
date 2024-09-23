/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:23:19 by irozhkov          #+#    #+#             */
/*   Updated: 2024/07/12 19:07:14 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	input_isprint(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

std::string	check_len(std::string str, size_t max)
{
	std::string	changed_str;
	size_t		i;

	changed_str = "";
	if (str.length() > max)
	{
		changed_str.append(str, 0, max - 1);
		changed_str.append(".");
		return (changed_str);
	}
	else if (str.length() < max)
	{
		i = max - str.length();
		while (i--)
			changed_str.append(" ");
		return (changed_str + str);
	}
	return (str);
}

int	search_contact(Contact contacts[8])
{
	int			i;
	int			indx;
	size_t		max;
	char		ch;
	std::string	str;

	i = 0;
	ch = '1';
	max = 10;

	std::cout << std::endl;
	std::cout << GREEN << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << " ---------- ---------- ---------- ---------- " << RESET << std::endl;

	while (ch <= '8')
	{
		indx = ch - 1 - '0';
		if (!contacts[indx].get_first_name().empty())
		{
			i++;
			str = ch;
			std::cout << GREEN << "|" << check_len(str, max);
			str = contacts[indx].get_first_name();
			std::cout << "|" << check_len(str, max);
			str = contacts[indx].get_last_name();
			std::cout << "|" << check_len(str, max);
			str = contacts[indx].get_nickname();
			std::cout << "|" << check_len(str, max) << "|" << std::endl;
			std::cout << " ---------- ---------- ---------- ---------- " << RESET << std::endl;
		}
		ch++;
	}
	std::cout << std::endl;
	return (i);
}
