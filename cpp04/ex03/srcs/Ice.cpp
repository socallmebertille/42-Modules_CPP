/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:18:33 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 14:13:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria()
{
	std::cout << "Ice default constructor called ..." << std::endl;
	_typeMateria = "ice";
}

Ice::Ice(const Ice& cpy): AMateria(cpy)
{
	std::cout << "Ice cpy constructor called ..." << std::endl;
	*this = cpy;
}

Ice& Ice::operator=(const Ice& cpy)
{
	std::cout << "Ice copy assigment operator called ..." << std::endl;
	if (this != &cpy)
	{
		AMateria::operator=(cpy);
		_typeMateria = cpy._typeMateria;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice deconstructor called ..." << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *cloneIce = new Ice();
	return (cloneIce);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
