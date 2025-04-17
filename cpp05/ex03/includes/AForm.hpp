/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:31:52 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 18:19:37 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _signed;
	const int _gradeSign;
	const int _gradeExec;
  public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExec);
	AForm(const AForm& cpy);
	AForm& operator=(const AForm& cpy);
	~AForm();
	std::string getName() const;
	bool getSigned() const;
	int getGradeSign() const;
	int getGradeExec() const;
	class GradeTooLowException: public std::exception {
	  public:
		virtual const char* what() const throw();
	};
	class GradeTooHighException: public std::exception {
	  public:
		virtual const char* what() const throw();
	};
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &flux, const AForm &myObject);

#endif