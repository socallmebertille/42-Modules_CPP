/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:33:43 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 19:29:48 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
	const Fixed	_x;
	const Fixed _y;

  public:
	Point();
	Point(const float x, const float y);
	Point(const Point& cpy);
	Point operator=(const Point& cpy);
	~Point();
	Fixed getXPoint() const;
	Fixed getYPoint() const;
};

#endif