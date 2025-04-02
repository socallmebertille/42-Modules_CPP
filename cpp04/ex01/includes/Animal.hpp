/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:01:41 by saberton          #+#    #+#             */
/*   Updated: 2025/04/02 14:51:02 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(const Animal& cpy);
	Animal& operator=(const Animal& cpy);
	virtual ~Animal();
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif