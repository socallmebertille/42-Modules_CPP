/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:19:04 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 12:20:08 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice
{
  protected:
	std::string _typeMateria;
  public:
	Ice();
	Ice(std::string const & type);
	Ice& operator=(const Ice& cpy);
	~Ice();
};

#endif