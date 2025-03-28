/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:33:43 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 18:34:53 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>

class Point
{
  private:
	int _rawBits;

  public:
	Point();
	Point(const Point& cpy);
	Point &operator=(const Point& cpy);
	~Point();
};

#endif