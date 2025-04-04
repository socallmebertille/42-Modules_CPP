/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:14:48 by saberton          #+#    #+#             */
/*   Updated: 2025/04/04 16:13:00 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("Default")
{
	std::cout << "Character default constructor called ..." << std::endl;
	for (int i(0); i < 4; i++)
		_slots[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character constructor of " << name << " called ..." << std::endl;
	for (int i(0); i < 4; i++)
		_slots[i] = NULL;
}

Character::Character(const Character& cpy)
{
	std::cout << "Character copy constructor of " << cpy._name << " called ..." << std::endl;
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	*this = cpy;
}

Character& Character::operator=(const Character& cpy)
{
	std::cout << "Character copy assigment operator of " << cpy._name << " called ..." << std::endl;
	if (this != &cpy)
	{
		_name = cpy._name;
		for (int i(0); i < 4; i++)
		{
			if (_slots[i])
				delete _slots[i];
			_slots[i] = NULL;
			if (cpy._slots[i])
				_slots[i] = cpy._slots[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character deconstructor of " << _name << " called ..." << std::endl;
	for (int i(0); i < 4; i++)
	{
		if (_slots[i])
		{
			delete _slots[i];
			_slots[i] = NULL;
		}
	}
}

std::string const & Character::getName() const { return (_name); }

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	int i(0);
	for (; i < 4; i++)
	{
		if (!_slots[i])
		{
			_slots[i] = m->clone();
			break ;
		}
	}
	if (m)
	{
		delete m;
		m = NULL;
	}
	if (i == 4)
		std::cout << "The materia slots are full, you have to unequip 1 slot." << std::endl;
}

void Character::unequip(int idx)
{
	if (_slots[idx])
	{
		delete _slots[idx];
		_slots[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !_slots[idx])
		return ;
	if (_slots[idx]->getType() == "ice" || _slots[idx]->getType() == "cure")
		_slots[idx]->use(target);
}
