/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/20 02:43:19 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2) {
		std::cerr << RED << "./convert <literal>" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
