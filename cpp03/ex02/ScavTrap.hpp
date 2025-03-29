/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:28:45 by saberton          #+#    #+#             */
/*   Updated: 2025/03/29 22:31:45 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{
  private:
	/* data */
  public:
	ScavTrap();
	ScavTrap(/* args */);
	ScavTrap(const ScavTrap& cpy);
	ScavTrap &operator=(const ScavTrap& cpy);
	~ScavTrap();
};

#endif