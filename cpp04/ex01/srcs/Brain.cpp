/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:17:52 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 18:23:53 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(/* args */)
{
	std::cout << "Brain default constructor called ..." << std::endl;
	for (int i(0); i < 100; i++)
		_ideas[i] = "idea n*" + i;
}

Brain::Brain(const Brain& cpy)
{
	// std::cout << "Brain copy constructor of " <<  << " called ..." << std::endl;
	*this = cpy;
}

Brain& Brain::operator=(const Brain& cpy)
{
	// std::cout << "Brain copy assigment operator of " <<  << " called ..." << std::endl;
	if (this != &cpy)
	{
		for (int i(0); i < 100; i++)
			_ideas[i] = cpy._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	// std::cout << "Brain destructor of " <<  << " called ..." << std::endl;
}
