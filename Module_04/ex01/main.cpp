/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:51:59 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/18 20:02:57 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int main()
{
	Animal **meta = new Animal*[100];
    for (int i = 0; i < 50; i++)
        meta[i] = new Cat();
    for (int i = 50; i < 100; i++)
        meta[i] = new Dog();
    for (int i = 0; i < 100; i++)
    {
        meta[i]->makeSound();
        delete meta[i];
    }
    delete [] meta;
	return (0);
}