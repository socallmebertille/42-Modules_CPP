/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:31:52 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 16:39:49 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form
{
  private:
	const std::string _name;
	bool _signed;
	
  public:
	Form();
	Form();
	Form(const Form& cpy);
	Form& operator=(const Form& cpy);
	~Form();
};

#endif