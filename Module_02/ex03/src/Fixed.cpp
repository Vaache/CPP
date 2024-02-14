/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:13:06 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/12 17:23:10 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fbit = 8;

Fixed::Fixed():fixed(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixed = num * (1 << this->fbit);
}

Fixed::Fixed (const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf(num * (1 << this->fbit));
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->fixed = other.fixed;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	if (this == &other)
		return(*this);
	// std::cout << "Copy assignment operator called" << std::endl;
	this->fixed = other.getRawBits();
	
	return(*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed:: getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
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