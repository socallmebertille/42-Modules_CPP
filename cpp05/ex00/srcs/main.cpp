/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/15 16:37:10 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;
	Bureaucrat n1("Marc");

	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	std::cout << n1;
	
	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	return (0);
}
