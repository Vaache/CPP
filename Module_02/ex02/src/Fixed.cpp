/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:13:06 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/11 19:23:21 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fbit = 8;

Fixed::Fixed():fixed(0)
{}

Fixed::Fixed(const int num)
{
	this->fixed = num * (1 << fbit);
}

Fixed::Fixed(const float fnum)
{
	this->fixed = roundf(fnum * (1 << this->fbit));
}

Fixed::Fixed(const Fixed &other)
{
	this->fixed = other.fixed;
}

Fixed::~Fixed()
{}

int Fixed::getRawBits( void ) const
{
	return this->fixed;
}

void Fixed::setRawBits( int const raw )
{
	this->fixed = raw;
}

float Fixed::toFloat( void ) const
{
	float fnum = static_cast<float>(this->fixed);
	return fnum /= (1 << this->fbit);
}

int Fixed::toInt( void ) const
{
	int num = static_cast<int>(this->fixed);
	return num / (1 << this->fbit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

Fixed& Fixed::operator =(const Fixed &other)
{
	this->fixed = other.fixed;
	return *this;
}

bool Fixed::operator >(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator >=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator <(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator <=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator ==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator !=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator +(const Fixed &other)
{
	return this->toFloat() + other.toFloat();
}

Fixed Fixed::operator -(const Fixed &other)
{
	return this->toFloat() - other.toFloat();
}

Fixed Fixed::operator *(const Fixed &other)
{
	return this->toFloat() * other.toFloat();
}

Fixed Fixed::operator /(const Fixed &other)
{
	return this->toFloat() / other.toFloat();
}

Fixed& Fixed::operator ++()
{
	this->fixed++;
	return *this;
}

Fixed Fixed::operator ++(int)
{
	Fixed tmp(*this);
	this->fixed++;
	return tmp;
}
Fixed& Fixed::operator --()
{
	this->fixed--;
	return *this;
}

Fixed Fixed::operator --(int)
{
	Fixed tmp(*this);
	this->fixed--;
	return tmp;
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