/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:18:22 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 14:13:34 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria()
{
	std::cout << "Cure default constructor called ..." << std::endl;
	_typeMateria = "cure";
}

Cure::Cure(const Cure& cpy): AMateria(cpy)
{
	std::cout << "Cure cpy constructor called ..." << std::endl;
	*this = cpy;
}

Cure& Cure::operator=(const Cure& cpy)
{
	std::cout << "Cure copy assigment operator called ..." << std::endl;
	if (this != &cpy)
	{
		AMateria::operator=(cpy);
		_typeMateria = cpy._typeMateria;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure deconstructor called ..." << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *cloneCure = new Cure();
	return (cloneCure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
