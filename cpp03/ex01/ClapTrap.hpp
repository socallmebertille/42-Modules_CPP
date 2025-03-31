/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:18:36 by saberton          #+#    #+#             */
/*   Updated: 2025/03/31 13:54:53 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
  protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& cpy);
	ClapTrap& operator=(const ClapTrap& cpy);
	~ClapTrap();
	std::string getName(void) const;
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif