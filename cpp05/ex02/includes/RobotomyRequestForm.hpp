/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:36:48 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 19:42:49 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
  private:
	/* data */
  public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& cpy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& cpy);
	~RobotomyRequestForm();
};

#endif