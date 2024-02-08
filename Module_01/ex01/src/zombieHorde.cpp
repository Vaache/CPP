/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:56:16 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/08 21:14:39 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *z1;

	z1 = new Zombie[N];
	for (int i = 0; i < N; ++i)
		z1[i] = Zombie(name);
	return z1;
}
