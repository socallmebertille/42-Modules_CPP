/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:01:53 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 12:04:18 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("AAnimal")
{
	std::cout << "AAnimal default constructor called ..." << std::endl;
}

AAnimal::AAnimal(const AAnimal& cpy)
{
	std::cout << "AAnimal copy constructor of " << cpy._type << " called ..." << std::endl;
	*this = cpy;
}

AAnimal& AAnimal::operator=(const AAnimal& cpy)
{
	std::cout << "AAnimal copy assigment operator of " << cpy._type << " called." << std::endl;
	if (this != &cpy)
		_type = cpy._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Aanimal destructor of " << _type << " called." << std::endl;
}

std::string AAnimal::getType(void) const { return (_type); }
