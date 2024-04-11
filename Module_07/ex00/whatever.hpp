/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:40:51 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/11 15:48:46 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
	void swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};

template <typename T>
	T max(T a, T b)
	{
		return a == b ? b : a > b ? a : b;
	}

template <typename T>
	T min(T a, T b)
	{
		return a == b ? b : a > b ? b : a;
	}

#endif