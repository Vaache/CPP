/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:15:53 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/27 17:26:48 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat B("Ava", 15);
			B.increaseGrade();
			std::cout << B << std::endl;
			B.increaseGrade();
			std::cout << B << std::endl;
			B.decreaseGrade();
			std::cout << B << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat B("Ava", 0);
			B.increaseGrade();
			std::cout << B << std::endl;
			B.increaseGrade();
			std::cout << B << std::endl;
			B.decreaseGrade();
			std::cout << B << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}