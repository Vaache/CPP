/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:39:23 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/08 20:54:57 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return 0;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(ScalarConverter::ExpHandler &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	
}