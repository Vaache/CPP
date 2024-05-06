/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:13:06 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/17 14:06:35 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fbit = 8;

Fixed::Fixed():fixed(0)
{
}

Fixed::Fixed (const int num)
{
	this->fixed = num * (1 << this->fbit);
}

Fixed::Fixed (const float num)
{
	this->fixed = roundf(num * (1 << this->fbit));
}

Fixed::Fixed(const Fixed &other)
{
	this->fixed = other.fixed;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	if (this == &other)
		return(*this);
	this->fixed = other.getRawBits();
	
	return(*this);
}

Fixed::~Fixed()
{
}

int Fixed:: getRawBits( void ) const
{
	return (this->fixed);
}

void Fixed::setRawBits( int const raw )
{
	this->fixed = raw;
}

float Fixed::toFloat(void) const
{
	float tof = static_cast<float>(this->fixed);
	return (tof / (1 << this->fbit));	
}

int Fixed::toInt( void ) const
{
	int toi = static_cast<int>(this->fixed);
	return (toi / (1 << this->fbit));
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->fixed > other.fixed);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->fixed >= other.fixed);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->fixed < other.fixed);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->fixed <= other.fixed);
}

bool Fixed::operator ==(const Fixed &other) const
{
	return (this->fixed == other.fixed);
}

bool Fixed::operator !=(const Fixed &other) const
{
	return !(this->fixed == other.fixed);
}

Fixed Fixed::operator +(const Fixed &other)
{
	Fixed temp;
	temp.fixed = this->fixed + other.fixed;
	return (temp);
}	

Fixed Fixed::operator -(const Fixed &other)
{
	Fixed temp;
	temp.fixed = this->fixed - other.fixed;
	return (temp);
}

Fixed Fixed::operator *(const Fixed &other)
{
	Fixed temp(this->toFloat() * other.toFloat());
	return (temp);
}	

Fixed Fixed::operator /(const Fixed &other)
{
	Fixed temp(this->fixed / other.fixed);
	return (temp);
}	

Fixed& Fixed::operator++()
{
	this->fixed++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixed++;
	return(temp);
}

Fixed& Fixed::operator--()
{
	this->fixed--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixed--;
	return(temp);
}

Fixed Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1> obj2  ? obj1 : obj2);
}

const Fixed Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 > obj2  ? obj1 : obj2);
}

Fixed Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return (obj1 < obj2  ? obj2 : obj1);
}

const Fixed Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 < obj2  ? obj2 : obj1);
}

std::ostream& operator << (std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();		
	return os;	
}