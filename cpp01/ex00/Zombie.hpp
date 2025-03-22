/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:06:18 by bertille          #+#    #+#             */
/*   Updated: 2025/03/21 23:04:24 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class   Zombie
{
  public:
    Zombie(std::string newName);
    ~Zombie();
    void    announce( void );
  private:
    std::string name;
};

#endif