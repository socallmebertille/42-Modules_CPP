/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:31:49 by saberton          #+#    #+#             */
/*   Updated: 2025/04/17 17:16:26 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _gradeSign(50), _gradeExec(40) {}

AForm::AForm(std::string name, int gradeSign, int gradeExec): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& cpy): _name(cpy._name), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec) { *this = cpy; }

AForm& AForm::operator=(const AForm& cpy)
{
	if (this != &cpy)
		_signed = cpy._signed;
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const { return (_name); }

bool AForm::getSigned() const { return (_signed); }

int AForm::getGradeSign() const { return (_gradeSign); }

int AForm::getGradeExec() const { return (_gradeExec); }

const char* AForm::GradeTooLowException::what() const throw() { return ("Grade to low !"); }

const char* AForm::GradeTooHighException::what() const throw() { return ("Grade to high !"); }

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &flux, const AForm &myObject)
{
	flux << "AForm " << myObject.getName() << " is";
	if (myObject.getSigned() == false)
		flux << " not";
	flux << " signed." << std::endl;
	flux << "This AForm required at least a grade " << myObject.getGradeSign() << " \
to be signed and " << myObject.getGradeExec() << " to be executed." << std::endl;
	return (flux);
}
