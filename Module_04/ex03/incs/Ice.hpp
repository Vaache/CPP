/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:54:15 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/22 20:54:28 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"


class Ice : public AMateria
{
public:
	Ice();
	Ice(const std::string &type);
	Ice(const Ice &other);
	Ice& operator =(const Ice &other);
	~Ice();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
