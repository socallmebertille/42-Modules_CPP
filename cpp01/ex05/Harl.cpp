/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:10:14 by saberton          #+#    #+#             */
/*   Updated: 2025/03/25 14:37:34 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Constructor called ..." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Destructor called ..." << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon \
costs more money. You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon \
for free. I’ve been coming for years, whereas you started \
working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak \
to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i(0); i < 4; i++)
	{
		if (level == type[i])
		{
			(this->*function[i])();
			return ;
		}
	}
	std::cout << "ERROR" << std::endl << "Invalid comments." << std::endl;
}
