/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:47:46 by bertille          #+#    #+#             */
/*   Updated: 2025/05/01 23:24:34 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& cpy) { *this = cpy; }

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy)
{
	if (this != &cpy)
	{

	}
	return(*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::initElems(std::string elems)
{
	std::istringstream iss(elems);
	std::string token;
	while (iss >> token)
	{
		for (size_t i = 0; i < token.size(); ++i)
		{
			if (!isdigit(token[i]))
			{
				if (token[i] == '-')
					throw(std::runtime_error("Numbers can only be positive."));
				else
					throw(std::runtime_error("Wrong type of characters -> only numbers."));
			}
		}
		int myNb = atoi(token.c_str());
		_d.push_back(myNb);
		_l.push_back(myNb);
		if (_l.size() > 3000 || _d.size() > 3000)
			throw(std::runtime_error("Number of elements to sort -> max 3000."));
	}
}

// std::deque<int> PmergeMe::getDeque(void) { return(_d); }

// std::list<int> PmergeMe::getList(void) { return(_l); }

void PmergeMe::printDeque(void) const
{
	std::cout << YELLOW << " Deque" << RESET << " : ";
	for (std::deque<int>::const_iterator it = _d.begin(); it != _d.end(); ++it)
	{
		if (it == _d.begin())
			std::cout << "[ " << CYAN << *it;
		else
			std::cout << " " << *it;
	}
	std::cout << RESET << " ]" << std::endl;
}

void PmergeMe::printList(void) const
{
	std::cout << PINK << " List" << RESET << " : ";
	for (std::list<int>::const_iterator it = _l.begin(); it != _l.end(); ++it)
	{
		if (it == _l.begin())
			std::cout << "[ " << CYAN << *it;
		else
			std::cout << " " << *it;
	}
	std::cout << RESET << " ]" << std::endl;
}

void	displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm* localTime = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
	std::cout << std::string(buffer);
}

void PmergeMe::sortAlgo(void)
{
	std::cout << BOLD << "Before" << RESET;
	printDeque();
	std::cout << BOLD << "Before" << RESET;
	printList();

	std::cout << std::endl << "		———————————		" << std::endl << std::endl;

	clock_t start = clock();

	//________________ALGO____________________



	//________________________________________

	clock_t end = clock();

	std::cout << BOLD << "After" << RESET;
	printDeque();
	std::cout << BOLD << "After" << RESET;
	printList();

	std::cout << std::endl << "		———————————		" << std::endl << std::endl;

	std::cout << "Time to process a range of " << _d.size() << " elements with std::" << "deque" << ": ";
	float elapsed_secs = float(end - start) / CLOCKS_PER_SEC;
	float elapsed_us = elapsed_secs * 1000000;
	std::cout << elapsed_us << " us" << std::endl;
}
