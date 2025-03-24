/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:13:22 by saberton          #+#    #+#             */
/*   Updated: 2025/03/24 18:22:01 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl comment;
    std::string Harl::*p(NULL);
    
    p = &Harl::level;
    comment.*p = "DEBUG";
    comment.complain(comment.*p);

    // void    (Harl::*f)(void);
    // f = &Harl::complain;
	return (0);
}