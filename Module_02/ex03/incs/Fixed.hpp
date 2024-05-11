/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:01:35 by vhovhann          #+#    #+#             */
/*   Updated: 2024/05/11 20:22:31 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixed;
	const static int fbit;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float fnum);
	Fixed(const Fixed &other);
	~Fixed();

	
	bool operator >(const Fixed &other) const;
	bool operator >=(const Fixed &other) const;
	bool operator <(const Fixed &other) const;
	bool operator <=(const Fixed &other) const;
	bool operator ==(const Fixed &other) const;
	bool operator !=(const Fixed &other) const;

	Fixed& operator =(const Fixed &other);
	Fixed operator +(const Fixed &other);
	Fixed operator -(const Fixed &other);
	Fixed operator *(const Fixed &other);
	Fixed operator /(const Fixed &other);
	
	Fixed& operator ++();
	Fixed& operator --();
	Fixed operator ++(int);
	Fixed operator --(int);

	static const Fixed min(const Fixed &obj1, const Fixed &obj2);
	static Fixed min(Fixed &obj1, Fixed &obj2);
	static Fixed max(Fixed &obj1, Fixed &obj2);
	static const Fixed max(const Fixed &obj1, const Fixed &obj2);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif