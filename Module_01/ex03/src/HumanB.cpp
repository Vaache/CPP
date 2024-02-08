/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:56:10 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/08 22:15:16 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB(std::string &name)
{
	this->name = name;
}

HumanB::HumanB(std::string &name, Weapon &wp)
{
	this->name = name;
	this->wp = wp;
}

HumanB::~HumanB()
{
	std::cout << "Destructokr HumanB ..." << std::endl;
}