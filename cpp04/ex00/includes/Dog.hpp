/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:43 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 14:17:14 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
  private:
	/* data */

  public:
	Dog();
	Dog(const Dog& cpy);
	Dog& operator=(const Dog& cpy);
	~Dog();
	virtual void makeSound(void) const;
};

#endif