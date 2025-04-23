/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:09:41 by saberton          #+#    #+#             */
/*   Updated: 2025/04/23 15:32:08 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	int len(5);
	
	Span sp = Span(len);
	std::cout << "\033[38;5;45m    SHORTEST ON SINGLE NB    \033[0m" << std::endl;
	try
	{
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << '\n';
	}
	std::cout << std::endl << "\033[38;5;45m    ADD TOO MUCH NB    \033[0m" << std::endl;
	try
	{
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << '\n';
	}
	std::cout << std::endl << "\033[38;5;45m    LONGEST ON EMPTY SPAN    \033[0m" << std::endl;
	Span sp2;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "\033[38;5;45m    ADD ON EMPTY SPAN    \033[0m" << std::endl;
	try
	{
		sp2.addNumber(2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}