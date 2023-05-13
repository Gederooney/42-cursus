/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:11:37 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/23 19:15:40 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(Point const &src);
		Point(float const x, float const y);
		~Point();
		Point & operator=(Point const & rhs);
		Fixed get_x() const;
		Fixed get_y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
