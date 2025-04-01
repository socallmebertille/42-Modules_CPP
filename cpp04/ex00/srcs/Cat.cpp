/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:27 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 14:16:31 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor called ..." << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& cpy): Animal(cpy)
{
	std::cout << "Cat copy constructor of " << cpy.type << " called ..." << std::endl;
	*this = cpy;
}

Cat& Cat::operator=(const Cat& cpy)
{
	std::cout << "Cat copy assigment operator of " << cpy.type << " called ..." << std::endl;
	if (this != &cpy)
	{
		Animal::operator=(cpy);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor of " << type << " called." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "I'm a cat, so I make a miaouwww sound." << std::endl;
}
