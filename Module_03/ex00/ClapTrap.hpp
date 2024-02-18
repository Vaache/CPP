/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:00:26 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/16 15:59:31 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name_;
	unsigned int _Hit_;
	unsigned int _Energy_;
	unsigned int _Attack_;

public:
	ClapTrap();
	ClapTrap(std::string &_name_);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	int	getHit();
	int	getEnergy();
	int	getAttack();
	std::string	getName();

	void	setHit(unsigned int _Hit_);
	void	setEnergy(unsigned int _Energy_);
	void	setAttack(unsigned int _Attack_);
	void	setName(std::string _name_);
	void	showInfo();
	
	
};


#endif