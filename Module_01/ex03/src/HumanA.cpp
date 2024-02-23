/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:58:49 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/22 14:40:40 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap)
{
	this->name = name;
	this->wp = &weap;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their" << wp->getType() << std::endl;
}