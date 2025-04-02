/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:43 by saberton          #+#    #+#             */
/*   Updated: 2025/04/02 15:05:34 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain* _dogBrain;
  public:
	Dog();
	Dog(const Dog& cpy);
	Dog& operator=(const Dog& cpy);
	~Dog();
	void makeSound(void) const;
	void getIdeas(int index, int nbIdeasDisplay) const;
};

#endif