/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedWithComments.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:00:58 by saberton          #+#    #+#             */
/*   Updated: 2025/03/27 19:02:49 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bitset>
#include <iostream>
static void printBinary(float _rawBits, int _fractionalBits)
{
	std::cout << "Ici on a un fixed-point sous forme : fixed<32," << _fractionalBits << ">" << std::endl;
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

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}
/*			Fixed(int)
_rawBits = intNb * (1 * 2^8)
CAR
1 << 8 revient a decale 1(= 00000001) de 8 bits vers la gauche soit 256(= 10000000)
*/
Fixed::Fixed(const int intNb)
{
	std::cout << "Int constructor called" << std::endl;
	printBinary(static_cast<float>(intNb), 0);
	_rawBits = intNb * (1 << _fractionalBits);
	printBinary(static_cast<float>(_rawBits), _fractionalBits);
}

/* 			Fixed(float)
ici ex avec 42,42 : 
42,42 * 256 = 10859,52
roundf(10859,52) = 10860
*/
Fixed::Fixed(const float floatNb)
{
	std::cout << "Float constructor called" << std::endl;
	printBinary(floatNb, 0);
	_rawBits = roundf(floatNb * (1 << _fractionalBits));
	printBinary(static_cast<float>(_rawBits), _fractionalBits);
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

/* 			toInt()
_rawBits >> _fractionalBits
CAR
on renvoie la partie entiere seulement enn decalant la partie entiere de 8 bits vers la droite
pour supprimer la mantisse
*/
int Fixed::toInt(void) const
{
	printBinary(static_cast<float>(_rawBits), _fractionalBits);
	std::cout << "My value as integer : ";
	return (_rawBits >> _fractionalBits);
}

/*			toFloat()
static_cast<float>(_rawBits) / (1 << _fractionalBits)
CAR
on renvoie dans un float le _rawBits initialement * 256 en le / 256
*/
float Fixed::toFloat(void) const
{
	printBinary(static_cast<float>(_rawBits), _fractionalBits);
	printBinary(static_cast<float>(_rawBits) / (1 << _fractionalBits), _fractionalBits);
	std::cout << "My value as float : ";
	return ((float)(_rawBits) / (float)(1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream& flux, const Fixed &myObject)
{
	flux << myObject.toFloat();
	return (flux);
}
