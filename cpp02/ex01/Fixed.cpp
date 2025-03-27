/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:53:51 by saberton          #+#    #+#             */
/*   Updated: 2025/03/27 19:02:46 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNb)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = intNb * (1 << _fractionalBits);
}

Fixed::Fixed(const float floatNb)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(floatNb * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed &Fixed::operator=(const Fixed& cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cpy)
		this->_rawBits = cpy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

int Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)(_rawBits) / (float)(1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream& flux, const Fixed &myObject)
{
	flux << myObject.toFloat();
	return (flux);
}
