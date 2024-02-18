/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DOg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:51:32 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/18 16:02:57 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
}
Dog::Dog(const Dog &other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->type = other.type;
}
Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}
Dog& Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;	
}

void Dog::makeSound() const
{
	std::cout << "Gaf Gaf Gaf" << std::endl;
}