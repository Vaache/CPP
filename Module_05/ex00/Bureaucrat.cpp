/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:22 by vhovhann          #+#    #+#             */
/*   Updated: 2024/03/04 15:18:14 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name_("nil"),_grade_(0)
{}

Bureaucrat::Bureaucrat(std::string _name_, int _grade_)
{
	if (_grade_ < 0)
		throw Bureaucrat::GradeTooHighException();
	if (_grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade_ = _grade_;
	this->_name_ = _name_;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	this->_grade_ = other._grade_;
	this->_name_ = other._name_;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat& other)
{
	this->_grade_ = other._grade_;
	this->_name_ = other._name_;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name_;
}

int			Bureaucrat::getGrade() const
{
	return this->_grade_;
}

const char * Bureaucrat::GradeTooLowException::what() const throw ()
{
	return "You entered a rating less than required.";
}

const char * Bureaucrat::GradeTooHighException::what() const throw ()
{
	return "You entered a rating that is more than required.";
}

void Bureaucrat::increaseGrade()
{
	if (--this->_grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decreaseGrade()
{
	if (++this->_grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator <<(std::ostream &os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (os);
}
