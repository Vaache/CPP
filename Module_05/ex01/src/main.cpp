/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:15:53 by vhovhann          #+#    #+#             */
/*   Updated: 2024/03/04 16:06:32 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat A("A", 20);
			Bureaucrat B("B", 15);
			Bureaucrat C("C", 70);
			Bureaucrat D("D", 100);

			Form form1("TEST", false, 140, 50);
			Form form2("TEST2", false, 30, 10);
			
			form1.beSigned(A);
			A.signForm(form1);
			std::cout << form1 << std::endl;

			form2.beSigned(B);
			B.signForm(form2);
			std::cout << form2 << std::endl;

			form1.beSigned(C);
			C.signForm(form1);
			
			form1.beSigned(D);
			D.signForm(form1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}	
}