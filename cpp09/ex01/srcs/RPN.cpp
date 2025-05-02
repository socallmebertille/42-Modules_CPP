/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:47:46 by bertille          #+#    #+#             */
/*   Updated: 2025/05/01 23:24:34 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& cpy) { *this = cpy; }

RPN& RPN::operator=(const RPN& cpy)
{
	if (this != &cpy)
		_stack = cpy._stack;
	return(*this);
}

RPN::~RPN() {}

void RPN::calculate(std::string rpn)
{
	while (!_stack.empty())
	_stack.pop();
	for (size_t i = 0; i < rpn.size(); ++i)
	{
		char c = rpn[i];
		if (isspace(c))
			continue;
		else if (isdigit(c))
			_stack.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2) { std::cout << "Error: missing a number at the beginning." << std::endl; return; }
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			int res;
			switch(c) {
				case '+': res = a + b; break;
				case '-': res = a - b; break;
				case '*': res = a * b; break;
				case '/': 
					if (b == 0) { std::cout << "Error: division by zero forbidden." << std::endl; return; }
					res = a / b; 
					break;
			}
			_stack.push(res);
		}
		else { std::cout << "Error: wrong character." << std::endl; return; }
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		std::cout << "Error: number left after making calcul." << std::endl;

}
