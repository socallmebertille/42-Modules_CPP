/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 00:29:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
	MutantStack() {}
	MutantStack(const MutantStack& cpy): std::stack<T>(cpy)  { *this = cpy; }
	MutantStack& operator=(const MutantStack& cpy)
	{
		if (this != &cpy)
			std::stack<T>::operator=(cpy);
		return (*this);
	}
	~MutantStack() {};
	void push(const T& value) { std::stack<T>::push(value); }
	T& top() { return std::stack<T>::top(); }
	const T& top() const { return std::stack<T>::top(); }
	size_t size() const { return std::stack<T>::size(); }

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif