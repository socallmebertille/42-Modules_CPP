/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:20 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 01:40:08 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName):name(newName), humanBWeapon("")
{
}

HumanB::~HumanB()
{
}

void    HumanB::attack( void )
{
    std::cout << name << " attacks with their " << humanBWeapon.getType() << std::endl;
}

void    HumanB::setWeapon( Weapon weapon )
{
    humanBWeapon = weapon;
}