/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:55:35 by saberton          #+#    #+#             */
/*   Updated: 2025/04/23 12:47:09 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> tab;
	tab.push_back(10);
	tab.push_back(42);
	tab.push_back(1337);

	try
	{
		::easyfind(tab, 42);
		::easyfind(tab, 10);
		::easyfind(tab, 9);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	return (0);
}