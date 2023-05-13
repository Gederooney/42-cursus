/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:11:32 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/25 08:24:22 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(Point const &src) : _x(src._x), _y(src._y)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point & Point::operator=(Point const & rhs)
{
	(void)rhs;
	return *this;
}

Fixed Point::get_x() const
{
	return this->_x;
}

Fixed Point::get_y() const
{
	return this->_y;
}

// name BSP
// Description: This function uses the barycentric coordinate system to determine if a point is inside a triangle.
// Parameters: a, b, c, point
// Return value: true or false
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const x = point.get_x();
	Fixed const y = point.get_y();
	Fixed const x1 = a.get_x();
	Fixed const y1 = a.get_y();
	Fixed const x2 = b.get_x();
	Fixed const y2 = b.get_y();
	Fixed const x3 = c.get_x();
	Fixed const y3 = c.get_y();

	Fixed const alpha = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
	Fixed const beta = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
	Fixed const gamma = Fixed((float)1.0) - alpha - beta;
	
	if (alpha > Fixed((float)0.0) && beta > Fixed((float)0.0) && gamma > Fixed((float)0.0))
		return true;
	else
	return false;
}

// Path: ex03/Point.hpp
