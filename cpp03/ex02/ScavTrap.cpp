/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:28:31 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 16:07:53 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called ..." << std::endl;
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor of " << name << " called ..." << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& cpy)
{
	std::cout << "ScavTrap copy constructor of " << cpy._name << " called ..." << std::endl;
	*this = cpy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &cpy)
{
	std::cout << "ScavTrap copy assignment operator " << cpy._name << " called" << std::endl;
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor of " << _name << " called ..." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " is already destroyed!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}
