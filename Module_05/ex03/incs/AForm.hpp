/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:14 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/07 17:05:43 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	bool		_signed_;
	const int	_gradeExec_;
	const int	_gradeSign_;
	const std::string	_name_;

public:
	AForm();
	AForm(std::string name, int GradeExec, int GradeSign);
	AForm(std::string name, bool _signed_, int GradeExec, int GradeSign);
	AForm(const AForm& other);
	virtual ~AForm();
	AForm& operator =(const AForm& other);

	class GradeTooHighException : public std::exception
	{
		public:
			const char * what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char * what() const throw();
	};

	bool getSigned() const;
	int getGradeExec() const;
	int getGradeSign() const;
	std::string getName() const;

	void checkExec(Bureaucrat const & executor) const;
	void checkSign() const;
	
	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator <<(std::ostream &os, const AForm& obj);

#endif