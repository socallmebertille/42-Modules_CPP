/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:47 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 00:25:35 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(), _dogBrain(new Brain())
{
	std::cout << "Dog default constructor called ..." << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& cpy): Animal(cpy), _dogBrain(NULL)
{
	std::cout << "Dog copy constructor of " << cpy._type << " called ..." << std::endl;
	*this = cpy;
}

Dog& Dog::operator=(const Dog& cpy)
{
	std::cout << "Dog copy assigment operator of " << cpy._type << " called ..." << std::endl;
	if (this != &cpy)
	{
		Animal::operator=(cpy);
		if (_dogBrain)
		{
			delete _dogBrain;
			_dogBrain = NULL;
		}
		if (cpy._dogBrain)
			_dogBrain = new Brain(*cpy._dogBrain);
	}
	return (*this);
}

Dog::~Dog()
{
	if (_dogBrain)
		delete _dogBrain;
	std::cout << "Dog destructor of " << _type << " called." << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "I'm a dog, so I make a 🐕 wafff sound." << std::endl;
}

void Dog::getIdeas(int index, int nbIdeasDisplay) const
{
	std::cout << "Dog's ideas : " << std::endl;
	_dogBrain->getIdeas(index, nbIdeasDisplay);
}
