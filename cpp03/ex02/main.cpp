/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:17:55 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 16:50:01 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "\033[38;5;220mInstances init :\033[0m" << std::endl;
	FragTrap p1("Jack");
	FragTrap p2("Marguerite");
	FragTrap cpyP2(p2);
	FragTrap def;

	def = p1;
	std::cout << std::endl;

	p1.attack(p2.getName());
	p2.takeDamage(30);
	p2.beRepaired(15);
	p2.attack("Jack");
	p2.highFivesGuys();

	std::cout << std::endl;
	std::cout << "\033[38;5;220mInstances delete :\033[0m" << std::endl;
	return (0);
}
