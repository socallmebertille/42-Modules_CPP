/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:19:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 12:21:11 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure
{
  protected:
	std::string _typeMateria;
  public:
	Cure();
	Cure(std::string const & type);
	Cure& operator=(const Cure& cpy);
	~Cure();
};

#endif