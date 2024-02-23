/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:01:39 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/22 14:34:52 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	std::cout << "Zombie Default constructor callde " << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie Destructor callde " << std::endl;
	std::cout << this->name << " destroyed!!!" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
