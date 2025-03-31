/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:36:40 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 18:52:35 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called ..." << std::endl;
	_name = "Default";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string name):ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor of " << name << " called ..." << std::endl;
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& cpy):ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
	std::cout << "DiamondTrap copy constructor of " << cpy._name << " called ..." << std::endl;
	*this = cpy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& cpy)
{
	std::cout << "DiamondTrap copy assigment operator of " << cpy._name << " called" << std::endl;
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
		ScavTrap::operator=(cpy);
		FragTrap::operator=(cpy);
		_name = cpy._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor of " << _name << " called ..." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Who am I ? eheheh ... I'm DiamondTrap " << _name << " & ClapTrap " << ClapTrap::_name << " !!! :)" << std::endl;
}
