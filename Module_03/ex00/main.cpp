/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:27:29 by vhovhann          #+#    #+#             */
/*   Updated: 2024/03/27 16:50:38 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::string name = "rob-bot";
	ClapTrap robot_1(name);
    ClapTrap robot_2;
	robot_1.showInfo();
    robot_1.attack("tree");
    robot_1.attack("enemy");
    robot_1.attack("another enemy");
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.beRepaired(2);
    robot_1.beRepaired(2);
    robot_1.beRepaired(2);
    robot_1.showInfo();

    robot_2 = robot_1;
    robot_2.showInfo();
	std::string name = "Hello";
	ClapTrap obj1(name);
	ClapTrap obj2 = obj1;
   	return (0);	
}