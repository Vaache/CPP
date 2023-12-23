/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:16:05 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/23 20:55:06 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contac.hpp"

void	Contact::set_first_name(std::string _first_name_)
{
	this->_first_name_ = _first_name_;
}

void	Contact::set_last_name(std::string _last_name_)
{
	this->_last_name_ = _last_name_;
}

void	Contact::set_nickname(std::string _nickname_)
{
	this->_nickname_ = _nickname_;
}

void	Contact::set_phone_number(std::string _phone_number_)
{
	this->_phone_number_ = _phone_number_;
}

void	Contact::set_darkest_secret(std::string _darkest_secret_)
{
	this->_darkest_secret_ = _darkest_secret_;
}

std::string	Contact::get_firs_name(void)
{
	return this->_first_name_;
}

std::string	Contact::get_last_name(void)
{
	return this->_last_name_;
}

std::string	Contact::get_nickname(void)
{
	return this->_nickname_;
}

std::string Contact::get_phone_number(void)
{
	return this->_phone_number_;
}

std::string Contact::get_darkest_secret(void)
{
	return this->_darkest_secret_;
}