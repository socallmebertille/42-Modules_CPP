/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:45:44 by bertille          #+#    #+#             */
/*   Updated: 2025/05/02 14:23:17 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Error: no argument given. " << std::endl;
		return (1);
	}
	PmergeMe a;
	return (0);
}