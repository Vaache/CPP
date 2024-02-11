/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:42:42 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/11 21:18:41 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"


class Point
{
private:
	const Fixed x;	
	const Fixed y;

public:
	Point();
	Point(const float num1, const float num2);
	Point(const Point& other);
	Point& operator =(const Point& other);
	~Point();
	float getX() const;
	float getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif