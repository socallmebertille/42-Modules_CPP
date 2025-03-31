/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:33:44 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 16:56:02 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
	std::cout << "FragTrap default constructor called ..." << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string name):ClapTrap(name)
{
	std::cout << "FragTrap constructor of " << name << " called ..." << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& cpy):ClapTrap(cpy)
{
	std::cout << "FragTrap copy constructor of " << cpy._name << " called ..." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& cpy)
{
	std::cout << "FragTrap copy assignment operator of " << cpy._name << " called" << std::endl;
	if (this != &cpy)
		ClapTrap::operator=(cpy);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor of " << _name << " called ..." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " wants to hight-fives you guys!" << std::endl;
}
