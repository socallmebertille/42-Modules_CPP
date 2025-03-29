/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:35:56 by saberton          #+#    #+#             */
/*   Updated: 2025/03/29 22:36:24 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>

class DiamondTrap
{
  private:
	/* data */
  public:
	DiamondTrap();
	DiamondTrap(/* args */);
	DiamondTrap(const DiamondTrap& cpy);
	DiamondTrap &operator=(const DiamondTrap& cpy);
	~DiamondTrap();
};

#endif