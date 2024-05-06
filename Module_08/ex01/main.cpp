/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:30:48 by vhovhann          #+#    #+#             */
/*   Updated: 2024/05/01 15:43:02 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <time.h>

int main()
{
	try
	{
		Span sp = Span(100000);
		for (int i = 0; i < 100000; ++ i)
			sp.addNumber(rand());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}