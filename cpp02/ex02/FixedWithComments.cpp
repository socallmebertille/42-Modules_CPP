/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedWithComments.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:56:52 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 18:29:51 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <bitset>

static void printBinary(float _rawBits, int _fractionalBits)
{
	std::bitset<32> bits(_rawBits);
	std::cout << "Valeur en binaire de " << _rawBits << " : ";
	for (int i = 31; i >= 0; --i) {
		if (i == 31)
			std::cout << "\033[35m"; // Violet = bit de signe
		else if (i >= _fractionalBits)
			std::cout << "\033[32m"; // Vert = exposant
		else
			std::cout << "\033[31m"; // Rouge = mantisse
		std::cout << bits[i];
		if (i == 31 || i == _fractionalBits)
			std::cout << " ";
	}
	std::cout << "\033[0m" << std::endl; // Reset couleurs
}

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

bool Fixed::operator>(const Fixed& cpy) const
{
	std::cout << "operateur > appele pour comparer : " << this->_rawBits << " et " << cpy._rawBits << std::endl;
	return (this->_rawBits > cpy._rawBits);
}

bool Fixed::operator<(const Fixed& cpy) const
{
	std::cout << "operateur < appele pour comparer : " << this->_rawBits << " et " << cpy._rawBits << std::endl;
	return (this->_rawBits < cpy._rawBits);
}

bool Fixed::operator>=(const Fixed& cpy) const { return (this->_rawBits >= cpy._rawBits); }

bool Fixed::operator<=(const Fixed& cpy) const { return (this->_rawBits <= cpy._rawBits); }

bool Fixed::operator==(const Fixed& cpy) const { return (this->_rawBits == cpy._rawBits); }

bool Fixed::operator!=(const Fixed& cpy) const { return (this->_rawBits != cpy._rawBits); }

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{ return ((fixed1 < fixed2) ? fixed1 : fixed2); }

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	bool rep(fixed1 < fixed2);
	std::string repBool;
	(rep == true) ? repBool = "true" : repBool = "false";
	std::cout << "operateur < return => " << repBool << " donc on return le fixed le + petit => ";
	if (rep == true) return (fixed1);
	return (fixed2);
	//return ((fixed1 < fixed2) ? fixed1 : fixed2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{ return ((fixed1 > fixed2) ? fixed1 : fixed2); }

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	bool rep(fixed1 > fixed2);
	std::string repBool;
	(rep == true) ? repBool = "true" : repBool = "false";
	std::cout << "operateur > return => " << repBool << " donc on return le fixed le + grand => ";
	if (rep == true) return (fixed1);
	return (fixed2);
	// return ((fixed1 > fixed2) ? fixed1 : fixed2);
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed tmp;
	printBinary(this->_rawBits, _fractionalBits);
	std::cout << "		      +" << std::endl;
	printBinary(fixed.getRawBits(), _fractionalBits);
	std::cout << "		      =" << std::endl;
	tmp._rawBits = (this->_rawBits + fixed.getRawBits());
	printBinary(tmp._rawBits, _fractionalBits);
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed tmp;
	tmp._rawBits = (this->_rawBits - fixed.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed tmp;
	printBinary(this->_rawBits, _fractionalBits);
	std::cout << "		      *" << std::endl;
	printBinary(fixed.getRawBits(), _fractionalBits);
	std::cout << "		      =" << std::endl;
	printBinary(this->_rawBits * fixed.getRawBits(), _fractionalBits);
	std::cout << "		      >> 8" << std::endl;
	tmp._rawBits = this->_rawBits * fixed.getRawBits() >> _fractionalBits;
	std::cout << "		      =" << std::endl;
	printBinary(tmp._rawBits, _fractionalBits);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed tmp;
	printBinary(this->_rawBits, _fractionalBits);
	std::cout << "		      >> 8" << std::endl;
	std::cout << "		      =" << std::endl;
	printBinary(this->_rawBits << _fractionalBits, _fractionalBits);
	std::cout << "		      /" << std::endl;
	printBinary(fixed.getRawBits(), _fractionalBits);
	tmp._rawBits = (this->_rawBits << _fractionalBits) / fixed.getRawBits();
	std::cout << "		      =" << std::endl;
	printBinary(tmp._rawBits, _fractionalBits);
	return (tmp);
}

Fixed &Fixed::operator++(void)
{
	printBinary(this->_rawBits, _fractionalBits);
	this->_rawBits++;
	std::cout << "return => ";
	printBinary(this->_rawBits, _fractionalBits);
	std::cout << "++++++++++++++++avant/pre : ";
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	printBinary(this->_rawBits, _fractionalBits);
	this->_rawBits++;
	std::cout << "return => ";
	printBinary(tmp._rawBits, _fractionalBits);
	std::cout << "apres/post+++++++++++++++ : ";
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

int Fixed::getRawBits(void) const { return (_rawBits); }

void Fixed::setRawBits(int const raw) { _rawBits = raw; }

int Fixed::toInt(void) const { return (_rawBits >> _fractionalBits); }

float Fixed::toFloat(void) const
{ return ((float)(_rawBits) / (float)(1 << _fractionalBits)); }

std::ostream &operator<<(std::ostream& flux, const Fixed &myObject)
{
	flux << myObject.toFloat();
	return (flux);
}
