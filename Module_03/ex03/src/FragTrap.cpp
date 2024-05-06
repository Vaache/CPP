/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:54:22 by vhovhann          #+#    #+#             */
/*   Updated: 2024/05/06 16:06:39 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string &_name_):ClapTrap(_name_)
{
	std::cout << "FragTrap Parameter constructor called" << std::endl;
	this->_Hit_ = 100;
	this->_Energy_ = 100;
	this->_Attack_ = 30;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called ..." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap copy constructor called ..." << std::endl;
	this->_Hit_ = other._Hit_;
	this->_Energy_ = other._Energy_;
	this->_Attack_ = other._Attack_;
	this->_name_ = other._name_;
}

FragTrap&	FragTrap::operator =(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_name_ = other._name_;
	this->_Attack_ = other._Attack_;
	this->_Energy_ = other._Energy_;
	return *this;
}
void FragTrap::highFivesGuys( void )
{
	std::cout << "high fives all form " << this->_name_ << " to all classes :)" <<std::endl;
}