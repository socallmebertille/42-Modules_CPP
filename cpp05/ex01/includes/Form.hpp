/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:31:52 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 18:19:37 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
	const std::string _name;
	bool _signed;
	const int _gradeSign;
	const int _gradeExec;
  public:
	Form();
	Form(std::string name, int gradeSign, int gradeExec);
	Form(const Form& cpy);
	Form& operator=(const Form& cpy);
	~Form();
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
};

std::ostream &operator<<(std::ostream &flux, const Form &myObject);

#endif