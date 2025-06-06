/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:22:46 by saberton          #+#    #+#             */
/*   Updated: 2025/03/25 14:40:02 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
    {
        std::string level(av[1]);
		Harl comment;
        comment.complain(level);
    }
	else
		std::cout << "ERROR" << std::endl << "Progam should be called like : ./harlFilter <INSTRUCTION>" << std::endl;
	return (0);
}
