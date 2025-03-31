/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:22:46 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 16:34:29 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap& cpy);
	FragTrap &operator=(const FragTrap& cpy);
	~FragTrap();
	void highFivesGuys(void);
};

#endif