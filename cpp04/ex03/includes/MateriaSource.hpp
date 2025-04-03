/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:37:35 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 15:02:58 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  public:
	MateriaSource();
	MateriaSource(const MateriaSource& cpy);
	MateriaSource& operator=(const MateriaSource& cpy);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif