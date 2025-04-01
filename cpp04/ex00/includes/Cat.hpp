/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:23 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 12:09:02 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat
{
private:
	/* data */
public:
	Cat();
	Cat(/* args */);
	Cat& operator=(const Cat& cpy);
	~Cat();
};

#endif