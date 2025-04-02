/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:01:53 by saberton          #+#    #+#             */
/*   Updated: 2025/04/02 23:00:33 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal default constructor called ..." << std::endl;
}

Animal::Animal(const Animal& cpy)
{
	std::cout << "Animal copy constructor of " << cpy._type << " called ..." << std::endl;
	*this = cpy;
}

Animal& Animal::operator=(const Animal& cpy)
{
	std::cout << "Animal copy assigment operator of " << cpy._type << " called." << std::endl;
	if (this != &cpy)
		_type = cpy._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor of " << _type << " called." << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "I'm a animal, so I make a default sound." << std::endl;
}

std::string Animal::getType(void) const { return (_type); }
