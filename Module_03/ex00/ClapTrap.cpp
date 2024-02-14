/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:04:37 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/14 16:29:18 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name_("NULL"),_Hit_(0),_Energy_(0),_Attack_(0)
{}

ClapTrap::ClapTrap(std::string &_name_)
{
	this->_name_ = _name_;
	this->_Hit_ = 10;
	this->_Energy_ = 10;
	this->_Attack_ = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destrucktor ..." << std::endl;
}

int	ClapTrap::getHit()
{
	return this->_Hit_;
}

int	ClapTrap::getEnergy()
{
	return this->_Energy_;
}
int	ClapTrap::getAttack()
{
	return this->_Attack_;	
}


std::string	ClapTrap::getName()
{
	return this->_name_;
}

void	ClapTrap::setHit(unsigned int _Hit_)
{
	this->_Hit_ = _Hit_;
}

void	ClapTrap::setEnergy(unsigned int _Energy_)
{
	this->_Energy_ = _Energy_;
}

void	ClapTrap::setAttack(unsigned int _Attack_)
{
	this->_Attack_ = _Attack_;
}

void	ClapTrap::setName(std::string _name_)
{
	this->_name_ = _name_;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->_Energy_ || !this->_Hit_)
		return ;
	std::cout << "ClapTrap" << this->_name_ <<  "attacks" << target << "causing";
	std::cout << this->_Attack_ << "points of damage!" << std::endl;
	-- this->_Energy_;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hit_ && this->_Hit_ >= amount)
	{
		std::cout << this->_name_ << "Received damage" << std::endl;
		this->_Hit_ -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Energy_ && this->_Hit_)
	{
		std::cout << this->_name_ << "Restores health" << std::endl;
		this->_Hit_ += amount;
		-- this->_Energy_;
	}
}