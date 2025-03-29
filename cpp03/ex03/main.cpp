/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:17:55 by saberton          #+#    #+#             */
/*   Updated: 2025/03/29 21:25:27 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap p1("Jack");
    ClapTrap p2("Marguerite");
    ClapTrap cpyP2(p2);
    std::cout << std::endl;
    p1.attack(p2.getName());
    p2.takeDamage(1);
    p2.beRepaired(1);
    p1.attack(p2.getName());
    p1.attack(p2.getName());
    p1.attack(p2.getName());
    p1.attack(p2.getName());
    std::cout << std::endl;
    return (0);
}
