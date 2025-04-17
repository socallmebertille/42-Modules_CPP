/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:37:02 by saberton          #+#    #+#             */
/*   Updated: 2025/04/17 17:14:19 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy): AForm(cpy) { *this = cpy; }
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		_target = cpy._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false || this->getGradeExec() < executor.getGrade())
		return throw GradeTooLowException();
	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << "The robotomy of " << _target << " failed." << std::endl;
}
