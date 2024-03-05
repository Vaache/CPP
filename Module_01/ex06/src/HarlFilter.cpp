/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:08:09 by vhovhann          #+#    #+#             */
/*   Updated: 2024/03/05 20:53:00 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

void HarlF::complain( std::string level )
{
	std::string arr[] = {"DEBUG","INFO","WARNING","ERROR","NULL"};
	void(HarlF::*fptr[])(void)= {&HarlF::debug, &HarlF::info, &HarlF::warning, &HarlF::error};
	int i = 0;
	while (level != arr[i] && arr[i] != "NULL")
		++i;
	switch (i)
	{
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			exit(1);
	}
	while (arr[i] != "NULL")
		(this->*fptr[i++])();
}

void HarlF::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void HarlF::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"  << std::endl;
}

void HarlF::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. " << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void HarlF::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
