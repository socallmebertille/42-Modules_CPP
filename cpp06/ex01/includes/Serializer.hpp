/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 01:34:15 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

/*Colors*/
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"

# include <iostream>
# include <stdint.h>

typedef struct s_Data
{
	int value;
	std::string name;
} Data;

class Serializer
{
  private:
	Serializer();
	Serializer(const Serializer& cpy);
	Serializer& operator=(const Serializer& cpy);
	~Serializer();
	
  public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif