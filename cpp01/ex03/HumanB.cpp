/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:20 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:30:25 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : name(newName), humanBWeapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (humanBWeapon != NULL)
		std::cout << name << " attacks with their " << (*humanBWeapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	humanBWeapon = &weapon;
}
