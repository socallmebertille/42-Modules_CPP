/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 18:28:29 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	// std::cout << "\033[38;5;45m==========Init with wrong grade==========\033[0m" << std::endl;
	// try
	// {
	// 	Bureaucrat n1("ToHigh", 0);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Error : " << e.what() << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat n2("ToLow", 151);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Error : " << e.what() << std::endl;
	// }

	// std::cout << std::endl << "\033[38;5;45m==========Init copy==========\033[0m" << std::endl;
	// try
	// {
	// 	Bureaucrat n3("Marc", 5);
	// 	Bureaucrat n4;
	// 	Bureaucrat n5(n3);
	// 	n4 = n3;
	// 	std::cout << n3 << n4 << n5;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Error : " << e.what() << std::endl;
	// }
	
	std::cout << std::endl << "\033[38;5;45m==========Can sign==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 5);
		Form form("Contract", 10, 5);
		std::cout << n;
		std::cout << form;
		n.signForm(form);
		std::cout << form;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[38;5;45m==========Can't sign==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 15);
		Form form("Contract", 10, 5);
		std::cout << n;
		std::cout << form;
		n.signForm(form);
		std::cout << form;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return (0);
}
