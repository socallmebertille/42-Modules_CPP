/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:17:55 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 16:17:46 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\033[38;5;220mInstances init :\033[0m" << std::endl;
	ScavTrap p1("Jack");
	ScavTrap p2("Marguerite");
	ScavTrap cpyP2(p2);
	ScavTrap def;

	def = p1;
	std::cout << std::endl;

	p1.attack(p2.getName());
	p2.takeDamage(20);
	p2.beRepaired(15);
	p2.attack("Jack");
	p2.guardGate();

	std::cout << std::endl;
	std::cout << "\033[38;5;220mInstances delete :\033[0m" << std::endl;
	return (0);
}
