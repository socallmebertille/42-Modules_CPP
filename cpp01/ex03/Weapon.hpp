/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:32 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 01:40:40 by bertille         ###   ########.fr       */
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
    void            setType(std::string newType);
    std::string&    getType();
};

#endif