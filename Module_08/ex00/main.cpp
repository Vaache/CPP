/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:41:03 by vhovhann          #+#    #+#             */
/*   Updated: 2024/05/01 14:38:01 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfinde.hpp"

int main()
{
	std::vector<int> arr;
	for (int i = 0; i < 10; ++ i)
		arr.push_back(i);
	try
	{
		std::cout << easyfinde(arr, 5) << std::endl;
		std::cout << easyfinde(arr, 1) << std::endl;
		std::cout << easyfinde(arr, 100) << std::endl;
		std::cout << easyfinde(arr, 200) << std::endl;
		std::cout << easyfinde(arr, 9) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}