/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:58:49 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/08 22:14:37 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanA::HumanA(str::string &name, Weapon &wp)
{
	this->name = name;
	this->wp = wp
}

HumanA::~HumanA()
{
	std::cout << "Destructor HumanA ..." << std::endl;
}

void HumanA::attack()
{
	std::cout << this->name << "attacks with their" << this->wp._getType() << std::endl;
}