/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:21:28 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/08 21:29:01 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator =(const ScalarConverter &other);
	~ScalarConverter();
public:
	static void convert(const char *arg);
	class ExpHandler : public std::exception
	{
		public:
			const char * what() const throw ();
	};
};

int validation(const std::string &str);
void char_cast(char c);
void double_cast(double num, const std::string &arg);
void float_cast(float num, const std::string &arg);
void int_cast(int num);

#endif