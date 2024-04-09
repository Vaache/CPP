/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:01:49 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/09 17:18:04 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *ptr = new Data;
	try
	{
		uintptr_t num = Serializer::serialize(ptr);

		Data *new_ptr = Serializer::deserialize(num);

		std::cout << "Ptr == " << ptr << std::endl;
		std::cout << "New Ptr == " << new_ptr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		delete ptr;
		return 1;
	}
	delete ptr;
	return 0;
}
