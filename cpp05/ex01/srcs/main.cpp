/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 16:24:48 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\033[38;5;45m==========Init with wrong grade==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n1("ToHigh", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat n2("ToLow", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[38;5;45m==========Init copy==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n3("Marc", 5);
		Bureaucrat n4;
		Bureaucrat n5(n3);
		n4 = n3;
		std::cout << n3 << n4 << n5;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[38;5;45m==========Operator tests==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n3("Melina", 5);
		std::cout << n3;
		for (int i(0); i < 10; i++)
			std::cout << ++n3;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat n4("Kiwi", 145);
		std::cout << n4;
		for (int i(0); i < 10; i++)
			std::cout << --n4;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return (0);
}
