/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:37:52 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 20:24:03 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed	area = Fixed(0.5f) *
		(a.getXPoint() * (b.getYPoint() - c.getYPoint())
		+ b.getXPoint() * (c.getYPoint() - a.getYPoint())
		+ c.getXPoint() * (a.getYPoint() - b.getYPoint()));
	if (area < Fixed(0))
		area = Fixed(0) - area;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A;
	Fixed	A1;
	Fixed	A2;
	Fixed	A3;

	A = area(a, b, c);
	A1 = area(point, b, c);
	A2 = area(a, point, c);
	A3 = area(a, b, point);
	return (A == (A1 + A2 + A3));
}
