/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:45:44 by bertille          #+#    #+#             */
/*   Updated: 2025/05/06 19:47:50 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "Error: no argument given. " << std::endl;
		return (1);
	}
	std::string newAv(av[1]);
	if (ac != 2)
	{
		for (int i(2); i < ac; i++)
		{
			newAv += " ";
			newAv += av[i];
		}
	}
	try
	{
		PmergeMe a;
		a.initElems(newAv);
		a.sortAlgo();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << BOLD << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}