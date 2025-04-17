/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/17 17:09:57 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << std::endl << "\033[38;5;45m==========Shrubbery Creation Form==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 13);
		ShrubberyCreationForm form("Home");
		std::cout << n;
		n.signForm(form);
		std::cout << form;
		form.execute(n);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[38;5;45m==========Robotomy Request Form==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 15);
		RobotomyRequestForm form("Home");
		std::cout << n;
		n.signForm(form);
		std::cout << form;
		std::cout << std::endl;
		form.execute(n);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[38;5;45m==========Presidential Pardon Form==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 5);
		PresidentialPardonForm form("Home");
		std::cout << n;
		n.signForm(form);
		std::cout << form;
		std::cout << std::endl;
		form.execute(n);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return (0);
}
