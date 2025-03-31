/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:18:45 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 16:37:56 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called ..." << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor of " << name << " called ..." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy) { std::cout << "ClapTrap copy constructor of " << cpy._name << " called ..." << std::endl; *this = cpy; }

ClapTrap& ClapTrap::operator=(const ClapTrap& cpy)
{
	std::cout << "ClapTrap copy assignment operator of " << cpy._name << " called" << std::endl;
	if (this != &cpy)
	{
		_name = cpy._name;
		_hitPoints = cpy._hitPoints;
		_energyPoints = cpy._energyPoints;
		_attackDamage = cpy._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor of " << this->getName() << " called ..." << std::endl;
}

std::string ClapTrap::getName(void) const { return (this->_name); }

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " regains " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}
