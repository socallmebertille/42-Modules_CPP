/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:28 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 01:40:28 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon      humanAWeapon;
public:
    HumanA(std::string newName, Weapon Weapon);
    ~HumanA();
    void    attack( void );
};

#endif