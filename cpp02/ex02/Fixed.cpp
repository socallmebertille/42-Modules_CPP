/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:53:51 by saberton          #+#    #+#             */
/*   Updated: 2025/03/27 21:41:17 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {}

Fixed::Fixed(const int intNb) { _rawBits = intNb * (1 << _fractionalBits); }

Fixed::Fixed(const float floatNb) { _rawBits = roundf(floatNb * (1 << _fractionalBits)); }

Fixed::Fixed(const Fixed &cpy) { *this = cpy; }

Fixed &Fixed::operator=(const Fixed& cpy)
{
	if (this != &cpy)
		this->_rawBits = cpy.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed& cpy)
{
	if (this->getRawBits() > cpy.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& cpy)
{
	if (this->getRawBits() < cpy.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& cpy)
{
	if (this->getRawBits() >= cpy.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& cpy)
{
	if (this->getRawBits() <= cpy.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& cpy)
{
	if (this->getRawBits() == cpy.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& cpy)
{
	if (this->getRawBits() != cpy.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& fixed)
{
	Fixed tmp;
	tmp._rawBits = this->_rawBits + fixed.getRawBits();
	// this->_rawBits = this->toFloat();
	return (tmp);//(*this);
}

Fixed Fixed::operator-(const Fixed& fixed)
{
	this->_rawBits = _rawBits - fixed.getRawBits();
	return (*this);
}

Fixed Fixed::operator*(const Fixed& fixed)
{
	this->_rawBits *= fixed.getRawBits();
	return (*this);
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	this->_rawBits /= fixed.getRawBits();
	return (*this);
}

Fixed &Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_rawBits++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_rawBits--;
	return (tmp);
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

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

std::ostream &operator<<(std::ostream& flux, const Fixed &myObject)
{
	flux << myObject.toFloat();
	return (flux);
}
