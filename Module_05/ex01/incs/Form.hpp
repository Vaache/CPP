/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:56:49 by vhovhann          #+#    #+#             */
/*   Updated: 2024/03/04 16:04:17 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	bool		_signed_;
	const int	_gradeExec_;
	const int	_gradeSign_;
	const std::string	_name_;

public:
	Form();
	Form(std::string name, bool _signed_, int GradeExec, int GradeSign);
	Form(const Form& other);
	~Form();
	Form& operator =(const Form& other);

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

	void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator <<(std::ostream &os, const Form& obj);

#endif