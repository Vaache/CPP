/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:17:47 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/17 21:18:17 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &_name_);
	ScavTrap(const ScavTrap &other);
	virtual ~ScavTrap();

	void guardGate();
	void attack(const std::string& target);
	ScavTrap&	operator =(const ScavTrap &other);
};

#endif