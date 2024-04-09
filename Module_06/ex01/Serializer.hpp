/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:55:21 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/09 14:59:23 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator =(const Serializer& other);
	~Serializer();
	
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif