/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:04:41 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:35:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int	main(void)
{
	Zombie	firstZombie("Patrick");
	firstZombie.announce();
	std::cout << std::endl;

	Zombie*	secondZombie = newZombie("Gerard");
	secondZombie->announce();
	std::cout << std::endl;

	randomChump("Violette");
	std::cout << std::endl;

	Zombie*	forthZombie = newZombie("Alfred");
	forthZombie->announce();
	std::cout << std::endl;

	delete secondZombie;
	delete forthZombie;
	// 1er zombie -> allocation dans stack
	//            -> se detruit seul a la fin de la scope
	return (0);
}