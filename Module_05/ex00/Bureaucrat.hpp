/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:45:00 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/27 17:26:21 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	std::string _name_;
	int			_grade_;

public:
	Bureaucrat();
	Bureaucrat(std::string _name_, int _grade_);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat& operator =(const Bureaucrat& other);
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char * what() const throw ();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char * what() const throw ();
	};
	
	void increaseGrade();
	void decreaseGrade();

	std::string getName() const;
	int			getGrade() const;

};

std::ostream& operator <<(std::ostream &os, const Bureaucrat& obj);

#endif