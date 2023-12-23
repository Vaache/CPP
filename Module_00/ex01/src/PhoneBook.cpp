/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:40:04 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/23 21:44:17 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	PhoneBook::pars_number(std::string _phone_number_)
{
	size_t	i = -1;

	while (++i < _phone_number_.length())
		if (!isdigit(_phone_number_[i]))
			return false;
	return true;
}

bool	PhoneBook::only_space(std::string _space_)
{
	size_t	i = -1;

	while (++i < _space_.length())
		if (_space_[i] != ' ')
			return true;
	return false;
}

void	PhoneBook::pars_set_dot(std::string &s1, std::string s2)
{
	if (s2.length() > 10)
		s1 = (s2.substr(0, 9) + '.');
	else
		s1 = s2;
}

void	PhoneBook::add(int i)
{
	std::string	str;

	PhoneBook::add_first_name(i);
	PhoneBook::add_last_name(i);
	PhoneBook::add_phone_number(i);

	std::cout << "Enter Nickname : ";
	getline(std::cin, str);
	if (std::cin.eof())
		exit(1);
	a[i].set_nickname(str);

	std::cout << "Enter Darkest Sectret : ";
	getline(std::cin, str);
	if (std::cin.eof())
		exit(1);
	a[i].set_darkest_secret(str);

	std::cout << std::endl;
	std::cout << "Contact added successfully." << std::endl;
	std::cout << std::endl;
}