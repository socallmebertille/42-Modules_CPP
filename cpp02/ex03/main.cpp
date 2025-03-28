/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:53:07 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 20:21:04 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void drawTriangle(Point const a, Point const b, Point const c, Point const point)
{
	Fixed minX = Fixed::min(a.getXPoint(), Fixed::min(b.getXPoint(), c.getXPoint()));
	Fixed minY = Fixed::min(a.getYPoint(), Fixed::min(b.getYPoint(), c.getYPoint()));
	Fixed maxX = Fixed::max(a.getXPoint(), Fixed::max(b.getXPoint(), c.getXPoint()));
	Fixed maxY = Fixed::max(a.getYPoint(), Fixed::max(b.getYPoint(), c.getYPoint()));
	int max_x = maxX.toInt();
	int min_y = minY.toInt();
	int max_y = maxY.toInt();

	for (int j = max_y; j >= min_y; j--)
	{
		for (int i = 0; i <= max_x; i++)
		{
			Point p(i, j);
			if (p.getXPoint() == a.getXPoint() && p.getYPoint() == a.getYPoint())
				std::cout << "A";
			else if (p.getXPoint() == b.getXPoint() && p.getYPoint() == b.getYPoint())
				std::cout << "B";
			else if (p.getXPoint() == c.getXPoint() && p.getYPoint() == c.getYPoint())
				std::cout << "C";
			else if (p.getXPoint() == point.getXPoint() && p.getYPoint() == point.getYPoint())
				std::cout << "\033[31m" << "P" << "\033[0m";
			else if (bsp(a, b, c, p))
				std::cout << "+";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int	main(void)
{
	Point const a(10,20);
	Point const b(2,1);
	Point const c(25,3);

	Point const point(12,15);
	std::cout << "Check my triangle : " << std::endl << std::endl;
	drawTriangle(a,b,c, point);
	bool repBool = bsp(a, b, c, point);
	std::string rep;
	(repBool == true) ? rep = "true" : rep = "false";
	if (repBool == true)
		std::cout << std::endl << "My point IS in my triangle : " << "\033[32m" << rep << "\033[0m" << std::endl;
	else
		std::cout << std::endl << "My point IS NOT in my triangle : " << "\033[31m" << rep << "\033[0m" << std::endl;

	Point const point2(2,4);
	std::cout << std::endl << "Check my triangle : " << std::endl << std::endl;
	drawTriangle(a,b,c, point2);
	repBool = bsp(a, b, c, point2);
	(repBool == true) ? rep = "true" : rep = "false";
	if (repBool == true)
		std::cout << std::endl << "My point IS in my triangle : " << "\033[32m" << rep << "\033[0m" << std::endl;
	else
		std::cout << std::endl << "My point IS NOT in my triangle : " << "\033[31m" << rep << "\033[0m" << std::endl;
	return (0);
}
