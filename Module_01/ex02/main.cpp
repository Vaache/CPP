/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:32:58 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/08 21:41:45 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << &str << std::endl;
	std::cout << &strREF << std::endl;
	std::cout << strPTR << std::endl;
	std::cout << std::endl;
	std::cout << str << std::endl;
	std::cout << strREF << std::endl;
	std::cout << *strPTR << std::endl;
	return 0;
}