/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:37:27 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/08 22:18:18 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{ (void)other; }

ScalarConverter& ScalarConverter::operator =(const ScalarConverter &other)
{ (void)other; return *this; }

ScalarConverter::~ScalarConverter()
{}

const char * ScalarConverter::ExpHandler::what() const throw ()
{
	return "You entered an incorrect argument";
}

// -inf, +inf and nan
// -inff, +inff and nanf

void ScalarConverter::convert(const char *arg)
{
	std::string str(arg);
	if (!validation(str))
		throw ScalarConverter::ExpHandler();
	size_t i = 0;
	while (i < str.length() && (str[i] == ' ' || str[i] == '\t'))
		++i;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if ((isdigit(str[i]) && (str.find(".", i) != std::string::npos) && (str.find("f", i) != std::string::npos) && str.length() > 3) \
			|| str == "nanf" || str == "-inff" || str == "+inff")
		float_cast(atof(arg), arg);
	else if ((isdigit(str[i]) && (str.find(".", i) != std::string::npos) && str.length() > 2) \
			|| str == "nan" || str == "-inf" || str == "+inf")
		double_cast(atof_l(arg, NULL), arg);
	else if (isdigit(str[i]) && (str.find(".", i) == std::string::npos) && (str.find("f", i) == std::string::npos))
		int_cast(atoi(arg));
	else if (str.length() == 1)
		char_cast(*arg);
}
