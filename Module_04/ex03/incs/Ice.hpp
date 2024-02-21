/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:54:15 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/20 20:01:42 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class ICE : public AMateria
{
public:
	ICE();
	ICE(const ICE &other);
	ICE& operator =(const ICE &other);
	~ICE();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
