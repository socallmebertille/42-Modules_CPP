/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:56:24 by saberton          #+#    #+#             */
/*   Updated: 2025/03/21 14:31:16 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
// #include "Contact.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	std::string	answer("Nothing");
	
	while (answer == "Nothing")
	{
		std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
		// std::cin >> answer;
		std::getline(std::cin, answer);
		if (answer == "ADD")
		{
			PhoneBook.add();
		}
		else if (answer == "SEARCH")
		{
			PhoneBook.search();
		}
		else if (answer == "EXIT")
		{
			PhoneBook.exit();
			return (0);
		}
		answer = "Nothing";
	}
	return (0);
}