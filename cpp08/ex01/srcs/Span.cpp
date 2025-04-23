/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:18:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/23 18:02:04 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0), _added(0), _storage(NULL)
{
	
}
Span::Span(unsigned int N): _N(N), _added(0), _storage(new int[N])
{
	for (unsigned int i(0); i < _N; i++)
		_storage[i] = 0;
}

Span::Span(const Span& cpy): _N(0), _added(0), _storage(NULL) { *this = cpy; }

Span& Span::operator=(const Span& cpy)
{
	if (this != &cpy)
	{
		if (_storage)
		{
			delete [] _storage;
			_storage = NULL;
		}
		_N = cpy._N;
		_added = cpy._added;
		if (_N > 0)
		{
			_storage = new int[_N];
			for (unsigned int i(0); i < _N; i++)
				_storage[i] = cpy._storage[i];
		}
	}
	return (*this);
}

Span::~Span()
{
	if (_storage)
		delete [] _storage;
}

unsigned int Span::getN() { return(_N); }

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
	_storage[_added] = number;
	_added++;
}

void Span::addMultipleNumbers(Span& rangeOfNumbers)
{
	if (!_N)
		throw(std::runtime_error("You've build a span with no space in it to store numbers"));
	if (_added >= _N)
	{
		std::stringstream ss;
		ss << _N;
		throw(std::runtime_error("Already " + ss.str() + " elements stored"));
	}
	// std::vector<int> _storage(_storage + _added, );
	// std::vector<int> tmp(rangeOfNumbers, rangeOfNumbers.end());
	// std::vector<int> tmp(rangeOfNumbers._storage, rangeOfNumbers + _added);
	// std::copy_backward(rangeOfNumbers, rangeOfNumbers + _added, _storage);
	// _storage[_added] = rangeOfNumbers;
	// _added += rangeOfNumbers.size();
}

int Span::shortestSpan() const
{
	if (_N == 0 || _storage == NULL)
		throw(std::runtime_error("No number stored yet"));
	if (_added < 2)
		throw std::runtime_error("Need at least 2 numbers to return the shortest");
	std::vector<int> tmp(_storage, _storage + _added);
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
	if (_N == 0 || _storage == NULL)
		throw(std::runtime_error("No number stored yet"));
	if (_added < 2)
		throw std::runtime_error("Need at least 2 numbers to return the longest");
	std::vector<int> tmp(_storage, _storage + _added);
	int min = *std::min_element(tmp.begin(), tmp.end());
	int max = *std::max_element(tmp.begin(), tmp.end());
	return (max - min);
}
