/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:50:27 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/09 19:19:28 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "Error !!!" << std::endl;
		return 1;
	}
	HarlF obj;

	obj.complain(argv[1]);
}