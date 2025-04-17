/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:29:14 by saberton          #+#    #+#             */
/*   Updated: 2025/04/17 18:41:38 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy): AForm(cpy) { *this = cpy; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		_target = cpy._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false || this->getGradeExec() < executor.getGrade())
		return throw GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
	{
		std::cerr << "Error : Can't create " << _target + "_shrubbery" << std::endl;
		return ;
	}
	file << "                   &&& &&  & &&\n\
              && &\\/&\\|& ()|/ @, &&\n\
              &\\/(/&/&||/& /_/)_&/_&\n\
           &() &\\/&|()|/&\\/ '%\" & ()\n\
          &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
        &&   && & &| &| /& & % ()& /&&\n\
         ()&_---()&\\&\\|&&-&&--%---()~\n\
             &&     \\|||\n\
                     |||\n\
                     |||\n\
                     |||\n\
               , -=-~  .-^- _";
}