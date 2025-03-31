/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:17:55 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 16:23:44 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "\033[38;5;220mInstances init :\033[0m" << std::endl;
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
    std::cout << "\033[38;5;220mInstances delete :\033[0m" << std::endl;
    return (0);
}
