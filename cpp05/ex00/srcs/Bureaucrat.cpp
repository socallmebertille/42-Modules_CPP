/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:59 by saberton          #+#    #+#             */
/*   Updated: 2025/04/15 16:34:54 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(1)
{
	std::cout << "Bureaucrat default constructor called ..." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(1)
{
	std::cout << "Bureaucrat constructor of " << name << " called ..." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): _name("Default")
{
	std::cout << "Bureaucrat copy constructor of " << cpy._name << " called ..." << std::endl;
	*this = cpy;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cpy)
{
	std::cout << "Bureaucrat copy assigment operator of " << cpy._name << " called ..." << std::endl;
	if (this != &cpy)
	{
		// _name = cpy.getName();
		_grade = cpy.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat deconstructor called." << std::endl;
}

std::string Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

std::ostream &operator<<(std::ostream &flux, const Bureaucrat &myObject)
{
	flux << myObject.getName() << ", bureaucrat name " << myObject.getGrade() << "." << std::endl;
	return (flux);
}