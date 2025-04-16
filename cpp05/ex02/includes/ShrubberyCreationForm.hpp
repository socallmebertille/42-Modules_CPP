/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:29:20 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 19:42:50 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
  private:
	/* data */
  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& cpy);
	~ShrubberyCreationForm();
};

#endif