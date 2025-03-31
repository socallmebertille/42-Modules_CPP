/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:28:31 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 16:45:17 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	std::cout << "ScavTrap default constructor called ..." << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout << "ScavTrap constructor of " << name << " called ..." << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& cpy):ClapTrap(cpy)
{
	std::cout << "ScavTrap copy constructor of " << cpy._name << " called ..." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &cpy)
{
	std::cout << "ScavTrap copy assignment operator " << cpy._name << " called" << std::endl;
	if (this != &cpy)
		ClapTrap::operator=(cpy);
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
