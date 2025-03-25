/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:13:22 by saberton          #+#    #+#             */
/*   Updated: 2025/03/25 14:18:05 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl comment;
	std::cout << std::endl;
	comment.complain("DEBUG");
	std::cout << std::endl;
	comment.complain("INFO");
	std::cout << std::endl;
	comment.complain("WARNING");
	std::cout << std::endl;
	comment.complain("ERROR");
	std::cout << std::endl;
	comment.complain("DEBUG");
	std::cout << std::endl;
	comment.complain("TEST");
	std::cout << std::endl;
	comment.complain("");
	std::cout << std::endl;
	comment.complain("ERROR");
	std::cout << std::endl;
	return (0);
}
