/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:19:04 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 14:04:44 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
  public:
	Ice();
	Ice(const Ice& cpy);
	Ice& operator=(const Ice& cpy);
	~Ice();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif