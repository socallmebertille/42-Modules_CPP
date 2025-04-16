/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 18:19:54 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;
  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& cpy);
	Bureaucrat& operator=(const Bureaucrat& cpy);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	Bureaucrat& operator++();
	Bureaucrat& operator--();
	class GradeTooHighException: public std::exception {
	  public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
	  public:
		virtual const char* what() const throw();
	};
	void signForm(Form& form);
};

std::ostream &operator<<(std::ostream &flux, const Bureaucrat &myObject);

#endif