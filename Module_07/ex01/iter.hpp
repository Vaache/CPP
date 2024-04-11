/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:17:36 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/11 17:56:44 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
	void print(const T &value)
	{
		std::cout << value << std::endl;
	}

template <typename T>
	void iter(const T arr, size_t size, void (*f)(const std::string &value))
	{
		for (size_t i = 0; i < size; ++ i)
			f(arr[i]);
	}

// template <typename T>
// 	void print(const T value)
// 	{
// 		std::cout << value << std::endl;
// 	}

// template <typename T>
// 	void iter(T *arr, size_t size, void (*function)(const T vale))
// 	{
// 		for (size_t i = 0; i < size; ++ i)
// 			function(arr[i]);
//  }

#endif