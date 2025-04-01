/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:43 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 12:08:56 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog
{
private:
	/* data */
public:
	Dog();
	Dog(/* args */);
	Dog& operator=(const Dog& cpy);
	~Dog();
};

#endif