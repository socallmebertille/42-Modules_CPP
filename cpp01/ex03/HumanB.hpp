/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:22 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:29:02 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
  private:
	std::string name;
	Weapon* humanBWeapon;

  public:
	HumanB(std::string newName);
	~HumanB();
	void attack(void);
	void setWeapon(Weapon& weapon);
};

#endif