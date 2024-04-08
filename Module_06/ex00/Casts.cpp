/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casts.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:01:33 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/08 22:20:53 by vhovhann         ###   ########.fr       */
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
	std::cout << "float : " << static_cast<float>(num);
	if (static_cast<float>(num) == num)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double : " << num;
	if (static_cast<double>(num) == num)
		std::cout << ".0";
	std::cout << std::endl;
}

void float_cast(float num, const std::string &arg)
{
	if (arg == "nanf" || arg == "+inff" || arg == "-inff")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
	}
	else
	{
		if (static_cast<int>(num) < 32 || static_cast<int>(num) > 126)
			std::cout << "char : Non displayable" << std::endl;
		else
			std::cout << "char : '" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(num) << std::endl;
	}
	std::cout << "float : " << num;
	if (static_cast<int>(num) == num)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double : " << num;
	if (static_cast<int>(num) == num)
		std::cout << ".0";
	std::cout << std::endl;
}

void double_cast(double num, const std::string &arg)
{
	if (arg == "nan" || arg == "+inf" || arg == "-inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
	}
	else
	{
		if (static_cast<int>(num) < 32 || static_cast<int>(num) > 126)
			std::cout << "char : Non displayable" << std::endl;
		else
			std::cout << "char : '" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(num) << std::endl;
	}
	std::cout << "float : " << static_cast<float>(num);
	if (static_cast<int>(num) == num)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double : " << num;
	if (static_cast<int>(num) == num)
		std::cout << ".0";
	std::cout << std::endl;
}

void char_cast(char c)
{
	std::cout << "char : '" << c << "'" << std::endl;
	std::cout << "int : " << static_cast<char>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double : " << static_cast<int>(c) << std::endl;
}