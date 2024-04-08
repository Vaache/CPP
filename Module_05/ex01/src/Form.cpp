/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:31:03 by vhovhann          #+#    #+#             */
/*   Updated: 2024/03/06 16:19:54 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_signed_(false),_gradeExec_(1),_gradeSign_(150),_name_("nil")
{}

Form::Form(std::string name, bool _signed_, int GradeExec, int GradeSign):_gradeExec_(GradeExec),_gradeSign_(GradeSign),_name_(name)
{
	if (this->_gradeSign_ > 150)
		throw Form::GradeTooLowException();
	if (this->_gradeSign_ < 1)
		throw Form::GradeTooHighException();
	this->_signed_ = _signed_;
}

Form::Form(const Form& other):_signed_(other._signed_),_gradeExec_(other._gradeExec_),\
									_gradeSign_(other._gradeSign_),_name_(other._name_)
{}

Form::~Form()
{}

Form& Form::operator =(const Form& other)
{
	if (this == &other)
		return *this;
	this->_signed_ = other._signed_;
	return *this;
}

bool Form::getSigned() const
{
	return this->_signed_;
}

int Form::getGradeExec() const
{
	return this->_gradeExec_;
}

int Form::getGradeSign() const
{
	return this->_gradeSign_;
}

std::string Form::getName() const
{
	return this->_name_;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_gradeSign_ >= bureaucrat.getGrade())
		this->_signed_ = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "The bureaucrat's assessment is too low.";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "The bureaucrat's assessment is too hight.";
}

std::ostream& operator <<(std::ostream &os, const Form& obj)
{
    os << obj.getName() << ", form GradeExec " << obj.getGradeExec() << ", ";
	os << "form GradeSign " << obj.getGradeSign() << ", form sined " << obj.getSigned() << ".";
    return (os);
}
