/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/17 19:01:06 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "\033[38;5;45m==========Intern tests==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		try
		{
			n.signForm(*rrf);
			rrf->execute(n);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat n("Melina", 25);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		try
		{
			n.signForm(*rrf);
			rrf->execute(n);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat n("Melina", 146);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		try
		{
			n.signForm(*rrf);
			rrf->execute(n);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[38;5;45m==========Incorrect form==========\033[0m" << std::endl;
	try
	{
		Bureaucrat n("Melina", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request ihihi", "Bender");
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return (0);
}
