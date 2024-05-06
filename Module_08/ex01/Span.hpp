/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:09:32 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/27 16:17:08 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPAN_HPP_
# define _SPAN_HPP_

#include <iostream>
#include <vector>
#include <iterator>

class Span
{
private:
	unsigned int N;
	std::vector<int> arr;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span& operator =(const Span &other);
	~Span();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();	
};

#endif