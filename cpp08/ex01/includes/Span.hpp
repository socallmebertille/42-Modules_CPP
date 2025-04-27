/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 00:29:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <sstream>
# include <algorithm>
# include <stdexcept>
# include <limits>

class Span
{
  private:
	unsigned int _N;
	unsigned int _added;
	std::vector <int> _storage;
  public:
	Span();
	Span(unsigned int N);
	Span(const Span& cpy);
	Span& operator=(const Span& cpy);
	~Span();
	unsigned int getN();
	void printStorage();
	void addNumber(int number);
	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();
	template <typename It>void addMultipleNumbers(It begin, It end)
	{
		if (!_N)
			throw(std::runtime_error("You've build a span with no space in it to store numbers"));
		if (_added >= _N)
		{
			std::stringstream ss;
			ss << _N;
			throw(std::runtime_error("Already " + ss.str() + " elements stored"));
		}
		if (_storage.size() + std::distance(begin, end) > _N)
			throw std::runtime_error("Not enough space to add all numbers!");
		_storage.insert(_storage.end(), begin, end);
		_added = (_storage.end() - _storage.begin());
	}
	int shortestSpan() const;
	int longestSpan() const;
};

#endif