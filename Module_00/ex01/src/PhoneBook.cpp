/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:40:04 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/25 14:39:26 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	PhoneBook::pars_number(std::string _phone_number_)
{
	size_t	i = -1;

	while (++i < _phone_number_.length())
		if (!std::isdigit(_phone_number_[i]))
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

void	PhoneBook::search(int count)
{
	int	i = 0;
	std::string	tmp;
	std::string	output;

	std::cout << std::endl;
	std::cout << "|  index  | First name | Last name | Nickname |" << std::endl;
	for (int j = 0; j < count; ++j)
	{
		std::cout << " ---------- ---------- ---------- ----------" << std::endl;
		std::cout << "|" << std::setw(10) << j << "|" << std::setw(10);
		pars_set_dot(output, a[i].get_firs_name());
		std::cout <<  output << "|" << std::setw(10);
		pars_set_dot(output, a[i].get_last_name());
		std::cout <<  output << "|" << std::setw(10);
		pars_set_dot(output, a[i].get_nickname());
		std::cout <<  output << "|" << std::endl;
	}
	std::cout << " ---------- ---------- ---------- ----------" << std::endl;
	int index = 0;
	if (count != 0)
	{
		while (1)
		{
			std::cout << "Enter index to display information : ";
			getline(std::cin, tmp);
			if (std::cin.eof())
				exit (1);
			index = std::atoi(tmp.c_str());
			if (index > count || tmp.empty() || index < 0 || std::isalpha(tmp[0]))
			{
				std::cout << "You entered an incorrect index!!!" << std::endl;
				continue ;
			}
			std::cout << std::endl;
			break ;
		}
		std::cout << "Firs Name : " << a[index].get_firs_name() << std::endl;
		std::cout << "Last Name : " << a[index].get_last_name() << std::endl;
		std::cout << "Nickame : " << a[index].get_nickname() << std::endl;
		std::cout << "Phone Number : " << a[index].get_phone_number() << std::endl;
		std::cout << "Darkest Secret : " << a[index].get_darkest_secret() << std::endl;
		std::cout << std::endl;
	}
}