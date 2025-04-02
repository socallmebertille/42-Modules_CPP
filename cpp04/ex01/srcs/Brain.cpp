/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:17:52 by saberton          #+#    #+#             */
/*   Updated: 2025/04/02 15:05:55 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called ..." << std::endl;
	for (int i(0); i < 100; i++)
		_ideas[i] = "idea n* ";
}

Brain::Brain(const Brain& cpy)
{
	std::cout << "Brain copy constructor called ..." << std::endl;
	*this = cpy;
}

Brain& Brain::operator=(const Brain& cpy)
{
	std::cout << "Brain copy assigment operator called." << std::endl;
	if (this != &cpy)
	{
		for (int i(0); i < 100; i++)
			_ideas[i] = cpy._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called ..." << std::endl;
}

void Brain::getIdeas(int index, int nbIdeasDisplay)
{
	// std::cout << "Brain ideas : " << std::endl;
	for (int i(index); i < nbIdeasDisplay; i++)
		std::cout << _ideas[i] << i << " " << std::endl;
}
