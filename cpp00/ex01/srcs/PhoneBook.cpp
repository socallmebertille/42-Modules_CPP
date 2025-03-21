/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:02:51 by saberton          #+#    #+#             */
/*   Updated: 2025/03/21 15:46:07 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// PhoneBook::PhoneBook():nbContact(0)
// {
// 	Contact	empty_contact;

// 	for (int i(0); i < 8; i++)
// 		phoneBook[i] = empty_contact;
// }

// PhoneBook::~PhoneBook()
// {
	
// }

void	PhoneBook::add()
{
	if (nbContact == 8)
	{
		int	oldest(0);
		while (oldest < nbContact)
		{
			if (phoneBook[oldest].getOldest() == 1)
				break ;
			oldest++;
		}
		if (oldest + 1 < nbContact)
			phoneBook[oldest + 1].newOldest();
		else
			phoneBook[0].newOldest();
		phoneBook[oldest].createContact();
	}
	else
	{
		if (nbContact == 0)
			phoneBook[nbContact].newOldest();
		phoneBook[nbContact].createContact();
		nbContact++;
	}
}

void	PhoneBook::search()
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|index     |first name|last name |nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i(0); i < nbContact; i++)
	{
		std::cout << "|";
		std::cout << i + 1;
		std::cout << "         |";
		std::cout << phoneBook[i].displayFirstName();
		std::cout << "|";
		std::cout << phoneBook[i].displayLastName();
		std::cout << "|";
		std::cout << phoneBook[i].displayNickname();
		std::cout << "|" << std::endl;
	}
	if (nbContact == 0)
	{
		std::cout << "There are no contacts in the phonebook." << std::endl;
		return ;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	int	i(0);
	while (i <= 0 || i > nbContact)
	{
		std::cout << "Choose an index to view contact details : " << std::endl;
		std::cin >> i;
		std::cin.ignore();
		if (i > 0 && i <= nbContact)
		{
			std::cout << "Contact number ";
			std::cout << i;
			std::cout << " details :" << std::endl;
			phoneBook[i - 1].displayContact();
			break ;
		}
		std::cout << "Index is invalid. Please, try again." << std::endl;
	}
}

void	PhoneBook::exit()
{
	return ;
}
