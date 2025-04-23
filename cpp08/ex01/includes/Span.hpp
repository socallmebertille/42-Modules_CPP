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
	int* _storage;
  public:
	Span();
	Span(unsigned int N);
	Span(const Span& cpy);
	Span& operator=(const Span& cpy);
	~Span();
	unsigned int getN();
	void addNumber(int number);
	void addMultipleNumbers(Span& rangeOfNumbers);
	int shortestSpan() const;
	int longestSpan() const;
};

#endif