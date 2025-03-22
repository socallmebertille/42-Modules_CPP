/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:06:22 by bertille          #+#    #+#             */
/*   Updated: 2025/03/21 23:11:06 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string newName):name(newName)
{
    std::cout << "Constuctor of zombie : " << name << "." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Destructor of zombie : " << name << "." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
