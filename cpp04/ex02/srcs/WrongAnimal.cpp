/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:44:31 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 16:44:56 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called ..." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
	std::cout << "WrongAnimal copy constructor of " << cpy._type << " called ..." << std::endl;
	*this = cpy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& cpy)
{
	std::cout << "WrongAnimal copy assigment operator of " << cpy._type << " called." << std::endl;
	if (this != &cpy)
		_type = cpy._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor of " << _type << " called." << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "I'm a WrongAnimal, so I make a default sound." << std::endl;
}

std::string WrongAnimal::getType(void) const { return (_type); }
