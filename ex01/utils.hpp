/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:24:55 by irozhkov          #+#    #+#             */
/*   Updated: 2024/07/12 18:49:40 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "colors.hpp"
# include "Contact.hpp"

int			input_isprint(std::string str);
std::string	check_len(std::string str, size_t max);
int			search_contact(Contact contacts[8]);

#endif
