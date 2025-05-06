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
		_d = cpy._d;
		_l = cpy._l;
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

void PmergeMe::printDeque(void) const
{
	std::cout << YELLOW << " Deque" << RESET << " : " << CYAN;
	for (std::deque<int>::const_iterator it = _d.begin(); it != _d.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
}

void PmergeMe::printList(void) const
{
	std::cout << PINK << " List" << RESET << " : " << CYAN;
	for (std::list<int>::const_iterator it = _l.begin(); it != _l.end(); ++it)
		std::cout << CYAN << *it << " ";
	std::cout << RESET << std::endl;
}


static std::vector<int> generateJacobsthal(int max)
{
	std::vector<int> jac;
	int a = 0, b = 1;
	while (b <= max)
	{
		jac.push_back(b);
		int tmp = b;
		b = b + 2 * a;
		a = tmp;
	}
	return (jac);
}

static std::vector<std::pair<int, int> > createPairs(const std::vector<int>& temp, int& unpaired, bool& hasUnpaired) {
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < temp.size(); i += 2) {
		if (i + 1 < temp.size()) {
			int a = temp[i], b = temp[i + 1];
			if (a > b) std::swap(a, b);
			pairs.push_back(std::make_pair(a, b));
		} else {
			unpaired = temp[i];
			hasUnpaired = true;
		}
	}
	return pairs;
}

// ========================= DEQUE ==================================================

static std::deque<int> extractWinnersDeque(const std::vector<std::pair<int, int> >& pairs) {
	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].first);
	return winners;
}

static void insertUnpairedDeque(std::deque<int>& winners, int unpaired) {
	std::deque<int>::iterator it = winners.begin();
	while (it != winners.end() && *it < unpaired)
		++it;
	winners.insert(it, unpaired);
}

static void insertLosersDeque(std::deque<int>& winners, const std::vector<std::pair<int, int> >& pairs,
					   const std::vector<int>& jac, std::vector<bool>& inserted) {
	for (size_t j = 0; j < jac.size(); ++j) {
		int idx = jac[j] - 1;
		if (idx >= 0 && idx < static_cast<int>(pairs.size()) && !inserted[idx]) {
			int winner = pairs[idx].first;
			int loser = pairs[idx].second;
			std::deque<int>::iterator it = std::find(winners.begin(), winners.end(), winner);
			if (it != winners.end()) ++it;
			while (it != winners.end() && *it < loser)
				++it;
			winners.insert(it, loser);
			inserted[idx] = true;
		}
	}
}

static void insertRemainingLosersDeque(std::deque<int>& winners, const std::vector<std::pair<int, int> >& pairs,
								std::vector<bool>& inserted) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (!inserted[i]) {
			int winner = pairs[i].first;
			int loser = pairs[i].second;
			std::deque<int>::iterator it = std::find(winners.begin(), winners.end(), winner);
			if (it != winners.end()) ++it;
			while (it != winners.end() && *it < loser)
				++it;
			winners.insert(it, loser);
		}
	}
}

static std::deque<int> fordJohnsonDeque(std::deque<int> input) {
	if (input.size() <= 1)
		return input;
	std::vector<int> temp(input.begin(), input.end());
	int unpaired = 0;
	bool hasUnpaired = false;
	std::vector<std::pair<int, int> > pairs = createPairs(temp, unpaired, hasUnpaired);
	std::deque<int> winners = extractWinnersDeque(pairs);
	winners = fordJohnsonDeque(winners);
	if (hasUnpaired)
		insertUnpairedDeque(winners, unpaired);
	std::vector<int> jac = generateJacobsthal(static_cast<int>(pairs.size()));
	std::vector<bool> inserted(pairs.size(), false);
	insertLosersDeque(winners, pairs, jac, inserted);
	insertRemainingLosersDeque(winners, pairs, inserted);
	return winners;
}

float PmergeMe::sortDeque(void)
{
	clock_t start = clock();
	_d = fordJohnsonDeque(_d);
	clock_t end = clock();
	float elapsed_secs = float(end - start) / CLOCKS_PER_SEC;
	float elapsed_us = elapsed_secs * 1000000;
	return (elapsed_us);
}

// ========================= LIST ===================================================

static std::list<int> extractWinnersList(const std::vector<std::pair<int, int> >& pairs) {
	std::list<int> winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].first);
	return winners;
}

static void insertUnpairedList(std::list<int>& winners, int unpaired) {
	std::list<int>::iterator it = winners.begin();
	while (it != winners.end() && *it < unpaired)
		++it;
	winners.insert(it, unpaired);
}

static void insertLosersList(std::list<int>& winners, const std::vector<std::pair<int, int> >& pairs,
					  const std::vector<int>& jac, std::vector<bool>& inserted) {
	for (size_t j = 0; j < jac.size(); ++j) {
		int idx = jac[j] - 1;
		if (idx >= 0 && idx < static_cast<int>(pairs.size()) && !inserted[idx]) {
			int winner = pairs[idx].first;
			int loser = pairs[idx].second;
			std::list<int>::iterator it = std::find(winners.begin(), winners.end(), winner);
			if (it != winners.end()) ++it;
			while (it != winners.end() && *it < loser)
				++it;
			winners.insert(it, loser);
			inserted[idx] = true;
		}
	}
}

static void insertRemainingLosersList(std::list<int>& winners, const std::vector<std::pair<int, int> >& pairs,
							   std::vector<bool>& inserted) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (!inserted[i]) {
			int winner = pairs[i].first;
			int loser = pairs[i].second;
			std::list<int>::iterator it = std::find(winners.begin(), winners.end(), winner);
			if (it != winners.end()) ++it;
			while (it != winners.end() && *it < loser)
				++it;
			winners.insert(it, loser);
		}
	}
}

static std::list<int> fordJohnsonList(std::list<int> input) {
	if (input.size() <= 1)
		return input;
	std::vector<int> temp(input.begin(), input.end());
	int unpaired = 0;
	bool hasUnpaired = false;
	std::vector<std::pair<int, int> > pairs = createPairs(temp, unpaired, hasUnpaired);
	std::list<int> winners = extractWinnersList(pairs);
	winners = fordJohnsonList(winners);
	if (hasUnpaired)
		insertUnpairedList(winners, unpaired);
	std::vector<int> jac = generateJacobsthal(static_cast<int>(pairs.size()));
	std::vector<bool> inserted(pairs.size(), false);
	insertLosersList(winners, pairs, jac, inserted);
	insertRemainingLosersList(winners, pairs, inserted);
	return winners;
}

float PmergeMe::sortList(void)
{
	clock_t start = clock();
	_l = fordJohnsonList(_l);
	clock_t end = clock();
	float elapsed_secs = float(end - start) / CLOCKS_PER_SEC;
	float elapsed_us = elapsed_secs * 1000000;
	return (elapsed_us);
}

// ==================================================================================


void PmergeMe::sortAlgo(void)
{
	std::cout << BOLD << "Before" << RESET;
	printDeque();
	std::cout << BOLD << "Before" << RESET;
	printList();
	// std::cout << "		———————————		" << std::endl;
	float timeDeque = sortDeque();
	float timeList = sortList();
	std::cout << BOLD << "After" << RESET;
	printDeque();
	std::cout << BOLD << "After" << RESET;
	printList();
	// std::cout << "		———————————		" << std::endl;
	std::cout << "Time to process a range of " << _d.size() << " elements with std::" << "deque" << ": ";
	if (timeDeque > timeList)
		std::cout << RED << timeDeque;
	else
		std::cout << GREEN << timeDeque;
	std::cout << RESET << " us" << std::endl;
	std::cout << "Time to process a range of " << _l.size() << " elements with std::" << "list" << ": ";
	if (timeList > timeDeque)
		std::cout << RED << timeList;
	else
		std::cout << GREEN << timeList;
	std::cout << RESET << " us" << std::endl;
}
