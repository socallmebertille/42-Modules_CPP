/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:55:35 by saberton          #+#    #+#             */
/*   Updated: 2025/04/23 13:15:49 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> container;
	container.push_back(10);
	container.push_back(42);
	container.push_back(1337);

	try
	{
		std::vector<int>::iterator it;
		it = easyfind(container, 42);
		std::cout << "Occurence of [" << *it << "] find at index[" << std::distance(container.begin(), it) << "]" << std::endl;
		it = easyfind(container, 10);
		std::cout << "Occurence of [" << *it << "] find at index[" << std::distance(container.begin(), it) << "]" << std::endl;
		it = easyfind(container, 9);
		std::cout << "Occurence of [" << *it << "] find at index[" << std::distance(container.begin(), it) << "]" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	return (0);
}