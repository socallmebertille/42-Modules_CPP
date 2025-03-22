/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:30 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 01:40:44 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon):type(weapon)
{
}

Weapon::~Weapon()
{
}

void   Weapon::setType(std::string newType)
{
    type = newType;
}

std::string& Weapon::getType()
{
    return (type);
}