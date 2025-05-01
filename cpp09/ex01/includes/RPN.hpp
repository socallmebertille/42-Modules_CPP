/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:48:08 by bertille          #+#    #+#             */
/*   Updated: 2025/05/01 23:03:24 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
  private:
	std::stack<int> _stack;
  public:
	RPN();
	RPN(const RPN& cpy);
	RPN& operator=(const RPN& cpy);
	~RPN();
	void calculate(std::string rpn);
};


#endif