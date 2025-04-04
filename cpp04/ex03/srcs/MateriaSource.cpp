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

MateriaSource::MateriaSource(): IMateriaSource()
{
	std::cout << "MateriaSource default constructor called ..." << std::endl;
	for (int i(0); i < 4; i++)
		_materiaSource[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& cpy): IMateriaSource(cpy)
{
	std::cout << "MateriaSource copy constructor called ..." << std::endl;
	*this = cpy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& cpy)
{
	std::cout << "MateriaSource copy assigment operator of called ..." << std::endl;
	if (this != &cpy)
	{
		for (int i(0); i < 4; i++)
		{
			if (_materiaSource[i])
			{
				delete _materiaSource[i];
				_materiaSource[i] = NULL;
			}
			if (cpy._materiaSource[i])
				_materiaSource[i] = cpy._materiaSource[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource deconstructor called ..." << std::endl;
	for (int i(0); i < 4; i++)
	{
		if (_materiaSource[i])
		{
			delete _materiaSource[i];
			_materiaSource[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i(0); i < 4; i++)
	{
		if (!_materiaSource[i])
		{
			_materiaSource[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i(0); i < 4; i++)
	{
		if (_materiaSource[i] && _materiaSource[i]->getType() == type)
			return (_materiaSource[i]->clone());
	}
	std::cout << "The materia sources are not learned yet." << std::endl;
	return (NULL);
}
