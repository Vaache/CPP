/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:02:13 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/07 17:07:28 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
private:
	std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string & target);
	RobotomyRequestForm(const RobotomyRequestForm & other);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator =(const RobotomyRequestForm & other);

	static const int MaxGradeSidned = 72;
	static const int MaxGradeExec = 45;
	void execute(Bureaucrat const & executor) const;
};

#endif