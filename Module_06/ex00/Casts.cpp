/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casts.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:01:33 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/08 21:30:18 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void int_cast(int num)
{
	if (num >= 32 && num <= 126)
		std::cout << "char : '" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "int : " << num << std::endl;
	std::cout << "float : " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double : " << static_cast<int>(num) << std::endl;
}

void float_cast(float num, const std::string &arg)
{
	if (static_cast<int>(num) < 32 && static_cast<int>(num) > 126)
		std::cout << "char : Non displayable" << std::endl;
	else
	if (arg == "nanf" || arg == "+inff" || arg == "-inff")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
	}
	else
	{
		std::cout << "char : '" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(num) << std::endl;
	}
	std::cout << "float : " << num << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(num) << std::endl;
}

void double_cast(double num, const std::string &arg)
{
	if (static_cast<int>(num) < 32 && static_cast<int>(num) > 126)
		std::cout << "char : Non displayable" << std::endl;
	if (arg == "nan" || arg == "+inf" || arg == "-inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
	}
	else
	{
		std::cout << "char : '" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(num) << std::endl;
	}
	std::cout << "float : " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double : " << num << std::endl;
}

void char_cast(char c)
{
	std::cout << "char : '" << c << "'" << std::endl;
	std::cout << "int : " << static_cast<char>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double : " << static_cast<int>(c) << std::endl;
}