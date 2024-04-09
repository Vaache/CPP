/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:58:45 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/09 15:54:45 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer& other)
{ (void)other; }

Serializer::~Serializer()
{}

Serializer& Serializer::operator =(const Serializer& other)
{ (void)other; return *this; }

uintptr_t Serializer::serialize(Data* ptr)
{	
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
