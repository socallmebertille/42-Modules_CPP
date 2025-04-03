/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:10:36 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 13:55:48 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _typeMateria("Default Materia")
{
	std::cout << "AMateria default constructor called ..." << std::endl;
}

AMateria::AMateria(std::string const& type): _typeMateria(type)
{
	std::cout << "AMateria constructor of " << type << " called ..." << std::endl;
}

AMateria::AMateria(const AMateria& cpy)
{
	std::cout << "AMateria copy constructor of " << cpy._typeMateria << " called ..." << std::endl;
	*this = cpy;
}

AMateria& AMateria::operator=(const AMateria& cpy)
{
	std::cout << "AMateria copy assigment operator of " << cpy._typeMateria << " called ..." << std::endl;
	if (this != &cpy)
	{
		_typeMateria = cpy._typeMateria;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria deconstructor of " << _typeMateria << " called ..." << std::endl;
}

std::string const & AMateria::getType() const { return (_typeMateria); }

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " is going to use " << _typeMateria << std::endl;
}
