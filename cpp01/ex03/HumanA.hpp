/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:28 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:28:34 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
  private:
	std::string name;
	Weapon& humanAWeapon;

  public:
	HumanA(std::string newName, Weapon& Weapon);
	~HumanA();
	void attack(void);
};

#endif