/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:14:57 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 00:37:27 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Constuctor of 1 zombie." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Destructor of zombie : " << name << "." << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::giveName( std::string newName )
{
    name = newName;
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* zombieHorde = new Zombie[N];
    for (int i(0); i < N; i++)
        zombieHorde[i].giveName(name);
    return (zombieHorde);
}
