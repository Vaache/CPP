/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:24:08 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/08 20:33:20 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie *Z1;
	Z1 = newZombie("SASUN");
	Z1->announce();
	randomChump("Pro");
	delete Z1;
	
}