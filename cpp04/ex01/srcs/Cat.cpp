/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:27 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 00:25:14 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(), _catBrain(new Brain())
{
	std::cout << "Cat default constructor called ..." << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& cpy): Animal(cpy), _catBrain(NULL)
{
	std::cout << "Cat copy constructor of " << cpy._type << " called ..." << std::endl;
	*this = cpy;
}

Cat& Cat::operator=(const Cat& cpy)
{
	std::cout << "Cat copy assigment operator of " << cpy._type << " called ..." << std::endl;
	if (this != &cpy)
	{
		Animal::operator=(cpy);
		if (_catBrain)
		{
			delete _catBrain;
			_catBrain = NULL;
		}
		if (cpy._catBrain)
			_catBrain = new Brain(*cpy._catBrain);
	}
	return (*this);
}

Cat::~Cat()
{
	if (_catBrain)
		delete _catBrain;
	std::cout << "Cat destructor of " << _type << " called." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "I'm a cat, so I make a 🐈 miaouwww sound." << std::endl;
}

void Cat::getIdeas(int index, int nbIdeasDisplay) const
{
	std::cout << "Cat's ideas : " << std::endl;
	_catBrain->getIdeas(index, nbIdeasDisplay);
}
