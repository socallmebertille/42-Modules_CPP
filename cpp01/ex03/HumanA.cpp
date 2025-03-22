/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:24 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:28:40 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& weapon) : name(newName),
	humanAWeapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << humanAWeapon.getType() << std::endl;
}
