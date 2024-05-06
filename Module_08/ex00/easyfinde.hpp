/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfinde.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:12:42 by vhovhann          #+#    #+#             */
/*   Updated: 2024/05/01 15:13:00 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFINDE_HPP
# define EASYFINDE_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

template <typename T>
	int easyfinde(const T &array, const int num)
	{
		// std::vector<int> array = arr;
		typename T::const_iterator ptr = std::find(array.cbegin(), array.cend(), num);
		if (ptr == array.cend())
			throw std::runtime_error("Number not finde");
		return *ptr;
	};

#endif