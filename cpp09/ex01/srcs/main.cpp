/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:45:44 by bertille          #+#    #+#             */
/*   Updated: 2025/05/02 01:50:19 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Error: no argument given. " << std::endl;
		return (1);
	}
	RPN calc;
	calc.calculate(av[1]);
	calc.calculate(av[1]);
	return (0);
}