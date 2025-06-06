/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:31:49 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 18:33:09 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _gradeSign(50), _gradeExec(40)
{
	// std::cout << "Form default constructor called ..." << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	// std::cout << "Form constructor of " << name << " called ..." << std::endl;
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& cpy): _name(cpy._name), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec)
{
	// std::cout << "Form copy constructor of " << cpy._name << " called ..." << std::endl;
	*this = cpy;
}

Form& Form::operator=(const Form& cpy)
{
	// std::cout << "Form copy assigment operator of " << cpy._name << " called ..." << std::endl;
	if (this != &cpy)
	{
		_signed = cpy._signed;
	}
	return (*this);
}

Form::~Form()
{
	// std::cout << "Form deconstructor of " << _name << " called." << std::endl;
}

std::string Form::getName() const { return (_name); }

bool Form::getSigned() const { return (_signed); }

int Form::getGradeSign() const { return (_gradeSign); }

int Form::getGradeExec() const { return (_gradeExec); }

const char* Form::GradeTooLowException::what() const throw() { return ("Grade to low !"); }

const char* Form::GradeTooHighException::what() const throw() { return ("Grade to high !"); }

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &flux, const Form &myObject)
{
	flux << "Form " << myObject.getName() << " is";
	if (myObject.getSigned() == false)
		flux << " not";
	flux << " signed." << std::endl;
	flux << "This form required at least a grade " << myObject.getGradeSign() << " \
to be signed and " << myObject.getGradeExec() << " to be executed." << std::endl;
	return (flux);
}
