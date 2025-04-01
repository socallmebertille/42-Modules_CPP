/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:01:53 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 14:15:13 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << "Animal default constructor called ..." << std::endl;
}

Animal::Animal(const Animal& cpy)
{
    std::cout << "Animal copy constructor of " << cpy.type << " called ..." << std::endl;
    *this = cpy;
}

Animal& Animal::operator=(const Animal& cpy)
{
    std::cout << "Animal copy assigment operator of " << cpy.type << " called." << std::endl;
    if (this != &cpy)
    {
        type = cpy.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor of " << type << " called." << std::endl;
}

std::string Animal::getType(void) const
{
    return (type);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal makes default sound." << std::endl;
}
