/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:47 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 14:17:10 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor called ..." << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& cpy): Animal(cpy)
{
	std::cout << "Dog copy constructor of " << cpy.type << " called ..." << std::endl;
	*this = cpy;
}

Dog& Dog::operator=(const Dog& cpy)
{
	std::cout << "Dog copy assigment operator of " << cpy.type << " called ..." << std::endl;
	if (this != &cpy)
	{
		Animal::operator=(cpy);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor of " << type << " called." << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "I'm a dog, so I make a wafff sound." << std::endl;
}
