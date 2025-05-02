/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:45:44 by bertille          #+#    #+#             */
/*   Updated: 2025/05/02 20:26:26 by saberton         ###   ########.fr       */
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
	// max 3000 int					OK
	// sortie :
	// before : list non-sort
	// after : list sort
	// Time to process a range of _N elements with std::vector: _T us
	// Time to process a range of _N elements with std::deque: _T us
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
		std::cout << BOLD << "Before" << RESET;
		a.printDeque();
		std::cout << BOLD << "Before" << RESET;
		a.printList();

		std::cout << std::endl << "		———————————		" << std::endl << std::endl;
	
		a.sortAlgo();
		std::cout << BOLD << "After" << RESET;
		a.printDeque();
		std::cout << BOLD << "After" << RESET;
		a.printList();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << BOLD << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}