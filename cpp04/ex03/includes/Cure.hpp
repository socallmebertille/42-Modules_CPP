/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:19:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 16:55:26 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
  public:
	Cure();
	Cure(const Cure& cpy);
	Cure& operator=(const Cure& cpy);
	~Cure();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif