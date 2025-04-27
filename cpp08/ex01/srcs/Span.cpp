/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:18:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/27 17:48:08 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0), _added(0), _storage(0) {}

Span::Span(unsigned int N): _N(N), _added(0), _storage(0) {}

Span::Span(const Span& cpy): _N(0), _added(0), _storage(0) { *this = cpy; }

Span& Span::operator=(const Span& cpy)
{
	if (this != &cpy)
	{
		_N = cpy._N;
		_added = cpy._added;
		_storage = cpy._storage;
	}
	return (*this);
}

Span::~Span() {}

unsigned int Span::getN() { return(_N); }

void Span::printStorage()
{
	for (unsigned int i(0); i < _added; ++i)
		std::cout << _storage[i] << std::endl;
}

void Span::addNumber(int number)
{
	if (!_N)
		throw(std::runtime_error("You've build a span with no space in it to store numbers"));
	if (_added >= _N)
	{
		std::stringstream ss;
		ss << _N;
		throw(std::runtime_error("Already " + ss.str() + " elements stored"));
	}
	_storage.push_back(number);
	_added++;
}
std::vector<int>::iterator Span::begin() { return (_storage.begin()); }

std::vector<int>::iterator Span::end() { return (_storage.end()); }

int Span::shortestSpan() const
{
	if (_N == 0)
		throw(std::runtime_error("No number stored yet"));
	if (_added < 2)
		throw std::runtime_error("Need at least 2 numbers to return the shortest");
	std::vector<int> tmp(_storage.begin(), _storage.end());
	std::sort(tmp.begin(), tmp.end());
	int shortest = std::numeric_limits<int>::max();
	for (unsigned int i(0); i < tmp.size() - 1; i++)
	{
		int diff = tmp[i + 1] - tmp[i];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

int Span::longestSpan() const
{
	if (_N == 0)
		throw(std::runtime_error("No number stored yet"));
	if (_added < 2)
		throw std::runtime_error("Need at least 2 numbers to return the longest");
	std::vector<int> tmp(_storage.begin(), _storage.end());
	int min = *std::min_element(tmp.begin(), tmp.end());
	int max = *std::max_element(tmp.begin(), tmp.end());
	return (max - min);
}
