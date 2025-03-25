/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:53:51 by saberton          #+#    #+#             */
/*   Updated: 2025/03/25 17:04:26 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy):_fixedPoint(cpy._fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed& cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cpy)
	{
		_fixedPoint = cpy._fixedPoint;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint); //raw value of the fixed-point value
}

void Fixed::setRawBits(int const raw)
{
	// sets the raw value of the fixed-point number
	//raw = 0;
	int newRaw;
	newRaw = raw;
	// getRawBits();
}
