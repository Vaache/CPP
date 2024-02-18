/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:50:51 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/18 18:37:20 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
}
Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = other.type;
}
Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}
Cat& Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;	
}

void Cat::makeSound() const
{
	std::cout << "Myau Myau Myau" << std::endl;
}