/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:32 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:30:07 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
  private:
	std::string type;

  public:
	Weapon(std::string weapon);
	~Weapon();
	void setType(std::string newType);
	const std::string& getType() const;
};

#endif