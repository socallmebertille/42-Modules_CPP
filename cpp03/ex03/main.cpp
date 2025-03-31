/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:17:55 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 18:08:45 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\033[38;5;220mInstances init :\033[0m" << std::endl;
	DiamondTrap p1("Jack");
	DiamondTrap p2("Marguerite");
	DiamondTrap cpyP2(p2);
	DiamondTrap def;

	def = p1;
	std::cout << std::endl;

	p1.attack(p2.getName());
	p2.takeDamage(30);
	p2.beRepaired(15);
	p2.attack("Jack");
	p1.takeDamage(30);
	p2.highFivesGuys();
	def.whoAmI();

	std::cout << std::endl;
	std::cout << "\033[38;5;220mInstances delete :\033[0m" << std::endl;
	return (0);
}
