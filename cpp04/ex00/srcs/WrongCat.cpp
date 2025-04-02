/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:48:22 by saberton          #+#    #+#             */
/*   Updated: 2025/04/02 20:25:46 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat default constructor called ..." << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& cpy): WrongAnimal(cpy)
{
	std::cout << "WrongCat copy constructor of " << cpy._type << " called ..." << std::endl;
	*this = cpy;
}

WrongCat& WrongCat::operator=(const WrongCat& cpy)
{
	std::cout << "WrongCat copy assigment operator of " << cpy._type << " called." << std::endl;
	if (this != &cpy)
		WrongAnimal::operator=(cpy);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor of " << _type << " called." << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "I'm a cat, so I make a 🐈 miaouwww sound." << std::endl;
}
