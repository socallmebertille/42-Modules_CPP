/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:23 by saberton          #+#    #+#             */
/*   Updated: 2025/04/02 15:05:26 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain*	_catBrain;
  public:
	Cat();
	Cat(const Cat& cpy);
	Cat& operator=(const Cat& cpy);
	~Cat();
	void makeSound(void) const;
	void getIdeas(int index, int nbIdeasDisplay) const;
};

#endif