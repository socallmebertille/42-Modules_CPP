/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:30 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:30:21 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon)
{
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string newType)
{
	type = newType;
}

const std::string& Weapon::getType() const
{
	return (type);
}
