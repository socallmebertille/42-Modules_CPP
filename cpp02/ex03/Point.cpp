/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:33:45 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 19:29:44 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& cpy): _x(cpy._x), _y(cpy._y) {}

Point Point::operator=(const Point& cpy) { return (Point(cpy)); }

Point::~Point() {}

Fixed Point::getXPoint() const { return (this->_x); }

Fixed Point::getYPoint() const { return (this->_y); }
