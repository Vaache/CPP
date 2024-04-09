/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:12:06 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/09 17:37:28 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	{
		Base *ptr;
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}
	{
		Base *ptr;
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}
	{
		Base *ptr;
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	return 0;
}