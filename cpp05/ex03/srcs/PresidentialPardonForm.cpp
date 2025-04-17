/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:40:40 by saberton          #+#    #+#             */
/*   Updated: 2025/04/17 17:13:29 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy): AForm(cpy) { *this = cpy; }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		_target = cpy._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false || this->getGradeExec() < executor.getGrade())
		return throw GradeTooLowException();
	std::cout << _target << " has been pardoned by aphod Beeblebrox." << std::endl;
}
