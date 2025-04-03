/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:37:00 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 14:37:11 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called ..." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& cpy)
{
	std::cout << "MateriaSource copy constructor of " << cpy._typeMateria << " called ..." << std::endl;
	*this = cpy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& cpy)
{
	std::cout << "MateriaSource copy assigment operator of " << cpy._typeMateria << " called ..." << std::endl;
	if (this != &cpy)
	{
		AMateria::operator=(cpy);
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource deconstructor of " << _typeMateria << " called ..." << std::endl;
}

void MateriaSource::learnMateria(AMateria*)
{
	_typeMateria;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria* newMateria;
	if (type == "ice")
		newMateria->clone();
	else if (type == "cure")
		newMateria->clone();
	else
		newMateria = NULL;
	return (newMateria);
}
