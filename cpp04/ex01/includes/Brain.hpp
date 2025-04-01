/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:16:27 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 18:01:57 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
  private:
	std::string _ideas[100];
  public:
	Brain(/* args */);
	Brain(const Brain& cpy);
	Brain& operator=(const Brain& cpy);
	~Brain();
};

#endif