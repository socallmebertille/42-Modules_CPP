/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:56:24 by saberton          #+#    #+#             */
/*   Updated: 2025/03/21 18:06:12 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <csignal>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	std::string	answer;
	
	while (true)
	{
		std::cout << "Please, type ADD, SEARCH or EXIT." << std::endl;
		std::getline(std::cin, answer);
		if (answer == "ADD")
			PhoneBook.add();
		else if (answer == "SEARCH")
			PhoneBook.search();
		else if (answer == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}