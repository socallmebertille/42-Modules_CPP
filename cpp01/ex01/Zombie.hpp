/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:14:27 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:34:01 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
  public:
	Zombie();
	~Zombie();
	void announce(void);
	void giveName(std::string newName);

  private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif