/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:39:29 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 19:42:31 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
  private:
	/* data */
  public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& cpy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& cpy);
	~PresidentialPardonForm();
};

#endif