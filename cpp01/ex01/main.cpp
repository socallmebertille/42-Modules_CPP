/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:14:16 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:34:19 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	newHorde;

	newHorde = zombieHorde(5, "Melinaaa");
	std::cout << "[* Horde] ";
	newHorde->announce();
	for (int i(0); i < 5; i++)
	{
		std::cout << "[" << i << "] ";
		newHorde[i].announce();
	}
	delete[] newHorde;
	return (0);
}
