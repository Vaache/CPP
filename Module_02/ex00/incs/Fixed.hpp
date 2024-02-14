/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:01:35 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/11 19:36:18 by vhovhann         ###   ########.fr       */
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
	Fixed(const Fixed &other);
	~Fixed();

	Fixed operator =(const Fixed &other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif