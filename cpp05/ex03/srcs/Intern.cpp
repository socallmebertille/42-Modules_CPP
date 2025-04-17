/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:45:35 by saberton          #+#    #+#             */
/*   Updated: 2025/04/17 18:51:43 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::Intern(const Intern& cpy) { *this = cpy; }

Intern& Intern::operator=(const Intern& cpy)
{
	if (this != &cpy)
	{

	}
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	for (int i(0); i < 3; i++)
	{
		if (types[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			for (int j(i + 1); j < 3; j++)
				delete forms[j];
			return (forms[i]);
		}
		delete forms[i];
	}
	std::cout << "Intern couldn't find form named : " << form << "." << std::endl;
	return (NULL);
}
