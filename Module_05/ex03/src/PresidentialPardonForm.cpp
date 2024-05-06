/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:21:51 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/07 17:09:17 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <dlfcn.h>
PresidentialPardonForm::PresidentialPardonForm():AForm("nil", PresidentialPardonForm::MaxGradeExec, PresidentialPardonForm::MaxGradeSidned),target("nil")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target):AForm(target, MaxGradeExec, MaxGradeSidned),target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other):AForm(other.target, MaxGradeExec, MaxGradeSidned),target(other.target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm & other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkExec(executor);
	this->checkSign();
	std::cout << AForm::getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// The bureaucrat's assessment is too low.RB45 has been robotomized successfully.
// RB45 form state is - signed: yes, required sign grade: 72, required execute grade: 45
// Jack executed TEST_0100
// TEST_0100 form state is - signed: yes, required sign grade: 25, required execute grade: 5