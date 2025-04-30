/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:45:44 by bertille          #+#    #+#             */
/*   Updated: 2025/04/30 18:26:46 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	std::ifstream input(av[1]);
	if (!input)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	try
	{
		BitcoinExchange btc;
		btc.getPrice(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}