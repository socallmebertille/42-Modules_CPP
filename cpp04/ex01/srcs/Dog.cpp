/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:47 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 16:42:58 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor called ..." << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& cpy): Animal(cpy)
{
	std::cout << "Dog copy constructor of " << cpy._type << " called ..." << std::endl;
	*this = cpy;
}

Dog& Dog::operator=(const Dog& cpy)
{
	std::cout << "Dog copy assigment operator of " << cpy._type << " called ..." << std::endl;
	if (this != &cpy)
		Animal::operator=(cpy);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor of " << _type << " called." << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "I'm a dog, so I make a 🐕 wafff sound." << std::endl;
}
