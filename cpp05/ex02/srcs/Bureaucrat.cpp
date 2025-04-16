/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:59 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 18:31:39 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
	// std::cout << "Bureaucrat default constructor called ..." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	// std::cout << "Bureaucrat constructor of " << name << " called ..." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): _name(cpy._name)
{
	// std::cout << "Bureaucrat copy constructor of " << cpy._name << " called ..." << std::endl;
	*this = cpy;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cpy)
{
	// std::cout << "Bureaucrat copy assigment operator of " << cpy._name << " called ..." << std::endl;
	if (this != &cpy)
	{
		_grade = cpy.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat deconstructor of " << _name << " called." << std::endl;
}

std::string Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

Bureaucrat& Bureaucrat::operator++()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
	return (*this);
}

Bureaucrat& Bureaucrat::operator--()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high !"); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low !"); }

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &flux, const Bureaucrat &myObject)
{
	flux << myObject.getName() << ", bureaucrat grade " << myObject.getGrade() << "." << std::endl;
	return (flux);
}
