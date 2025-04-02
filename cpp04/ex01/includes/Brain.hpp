/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:16:27 by saberton          #+#    #+#             */
/*   Updated: 2025/04/02 22:58:11 by bertille         ###   ########.fr       */
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
	Brain();
	Brain(const Brain& cpy);
	Brain& operator=(const Brain& cpy);
	~Brain();
	void getIdeas(int index, int nbIdeasDisplay) const;
};

#endif