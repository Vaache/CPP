/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:36 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/07 17:06:59 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_signed_(false),_gradeExec_(1),_gradeSign_(150),_name_("nil")
{}

AForm::AForm(std::string name, int GradeExec, int GradeSign):_gradeExec_(GradeExec),_gradeSign_(GradeSign),_name_(name)
{
	if (this->_gradeSign_ > 150)
		throw AForm::GradeTooLowException();
	if (this->_gradeSign_ < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(std::string name, bool _signed_, int GradeExec, int GradeSign):_gradeExec_(GradeExec),_gradeSign_(GradeSign),_name_(name)
{
	if (this->_gradeSign_ > 150)
		throw AForm::GradeTooLowException();
	if (this->_gradeSign_ < 1)
		throw AForm::GradeTooHighException();
	this->_signed_ = _signed_;
}

AForm::AForm(const AForm& other):_signed_(other._signed_),_gradeExec_(other._gradeExec_),\
									_gradeSign_(other._gradeSign_),_name_(other._name_)
{}

AForm::~AForm()
{}

AForm& AForm::operator =(const AForm& other)
{
	if (this == &other)
		return *this;
	this->_signed_ = other._signed_;
	return *this;
}

bool AForm::getSigned() const
{
	return this->_signed_;
}

int AForm::getGradeExec() const
{
	return this->_gradeExec_;
}

int AForm::getGradeSign() const
{
	return this->_gradeSign_;
}

std::string AForm::getName() const
{
	return this->_name_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_gradeSign_ >= bureaucrat.getGrade())
		this->_signed_ = true;
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "The bureaucrat's assessment is too low.";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "The bureaucrat's assessment is too hight.";
}


void AForm::checkExec(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->_gradeExec_)
        throw GradeTooLowException();
}

void AForm::checkSign() const
{
    if (!this->_signed_)
        throw std::runtime_error("Form cannot be signed\n"); 
}

std::ostream& operator <<(std::ostream &os, const AForm& obj)
{
    os << obj.getName() << " form state is - signed: " << (obj.getSigned() ? "yes" : "no")
       << ", required sign grade: "<< obj.getGradeSign()
        << ", required execute grade: "
        << obj.getGradeExec();
    return (os);
}
