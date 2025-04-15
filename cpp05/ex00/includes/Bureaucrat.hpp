/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/15 16:34:58 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
// # include <ostream>

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;
  public:
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(const Bureaucrat& cpy);
	Bureaucrat& operator=(const Bureaucrat& cpy);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
};

std::ostream &operator<<(std::ostream &flux, const Bureaucrat &myObject);

#endif