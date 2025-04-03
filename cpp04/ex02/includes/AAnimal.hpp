/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:01:41 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 11:27:51 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
  protected:
	std::string _type;

  public:
	AAnimal();
	AAnimal(const AAnimal& cpy);
	AAnimal& operator=(const AAnimal& cpy);
	virtual ~AAnimal();
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif