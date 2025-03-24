/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:02:51 by saberton          #+#    #+#             */
/*   Updated: 2025/03/23 18:11:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nbContact(0)
{
	Contact	empty_contact;

	for (int i(0); i < 8; i++)
		phoneBook[i] = empty_contact;
}

void PhoneBook::add()
{
	if (nbContact < 8)
	{
		phoneBook[nbContact].createContact();
		if (nbContact == 0)
			phoneBook[nbContact].newOldest();
		nbContact++;
	}
	else
	{
		int oldest(0);
		for (int i(0); i < 8; ++i)
		{
			if (phoneBook[i].getOldest() == 1)
			{
				oldest = i;
				break ;
			}
		}
		phoneBook[oldest].createContact();
		if (oldest + 1 < nbContact)
			phoneBook[oldest + 1].newOldest();
		else
			phoneBook[0].newOldest();
	}
}

void PhoneBook::search()
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
	int index(-1);
	while (true)
	{
		std::cout << "Choose an index to view contact details :" << std::endl;
		std::string input;
		if (!std::getline(std::cin, input))
			return ;
		std::stringstream ss(input);
		if (ss >> index && ss.eof() && index > 0 && index <= nbContact)
		{
			std::cout << "Contact number " << index << " details:" << std::endl;
			phoneBook[index - 1].displayContact();
			break ;
		}
		if (nbContact == 1)
			std::cout << "Invalid index. The number can only be 1." << std::endl;
		else
			std::cout << "Invalid index. Please enter a number between 1 and " << nbContact << "." << std::endl;
	}
}
