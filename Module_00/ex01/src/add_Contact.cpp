/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add_Parameters.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:20:58 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/23 21:43:37 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add_first_name(int i)
{
	std::string str;

	while (1)
	{
		std::cout << "Enter First Name : ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
		if (str.empty() || !only_space(str))
		{
			std::cout << std::endl;
			std::cout << "Wrong First Name!!!" << std::endl;
			std::cout << std::endl;
			continue ;
		}
		a[i].set_first_name(str);
		break ;
	}
}

void	PhoneBook::add_last_name(int i)
{
	std::string str;

	while (1)
	{
		std::cout << "Enter Last Name : ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
		if (str.empty() || !only_space(str))
		{
			std::cout << std::endl;
			std::cout << "Wrong Last Name!!!" << std::endl;
			std::cout << std::endl;
			continue ;
		}
		a[i].set_last_name(str);
		break ;
	}
}

void	PhoneBook::add_phone_number(int i)
{
	std::string str;

	while (1)
	{
		std::cout << "Enter Phone Number : ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
		if (str.empty() || !only_space(str) || !pars_number(str))
		{
			std::cout << std::endl;
			std::cout << "Wrong Phone Number!!!" << std::endl;
			std::cout << std::endl;
			continue ;
		}
		a[i].set_last_name(str);
		break ;
	}
}