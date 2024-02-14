/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:13:06 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/11 18:23:28 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



const int Fixed::fbit = 8;

Fixed::Fixed():fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed = num * (1 << fbit);
}

Fixed::Fixed(const float fnum)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf(fnum * (1 << this->fbit));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed = other.getRawBits();
}

Fixed& Fixed::operator =(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed = other.getRawBits();
	return *this;	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
	fnum /= (1 << this->fbit);
	return fnum;
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

/*
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
*/