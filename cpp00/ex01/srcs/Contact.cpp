/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:57:14 by saberton          #+#    #+#             */
/*   Updated: 2025/03/21 17:43:42 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact():oldest(0)
{
	
}


void	Contact::displayContact()
{
	std::cout << "First Name : " + firstName << std::endl;
	std::cout << "Last Name : " + lastName << std::endl;
	std::cout << "Nickname : " + nickname << std::endl;
	std::cout << "Phone Number : " + phoneNumber << std::endl;
	std::cout << "Darkest Secret : " + darkestSecret << std::endl;
}

std::string Contact::displayFirstName()
{
	if (firstName.size() == 10)
		return (firstName);
	else if (firstName.size() < 10)
	{
		std::stringstream ss;
		ss << std::setw(10) << std::left << firstName;
		return (ss.str());
	}
	return (firstName.substr(0, 9) + ".");
}

std::string Contact::displayLastName()
{
	if (lastName.size() == 10)
		return (lastName);
	else if (lastName.size() < 10)
	{
		std::stringstream ss;
		ss << std::setw(10) << std::left << lastName;
		return (ss.str());
	}
	return (lastName.substr(0, 9) + ".");
}

std::string Contact::displayNickname()
{
	if (nickname.size() == 10)
		return (nickname);
	else if (nickname.size() < 10)
	{
		std::stringstream ss;
		ss << std::setw(10) << std::left << nickname;
		return (ss.str());
	}
	return (nickname.substr(0, 9) + ".");
}

int	Contact::getOldest()
{
	if (oldest == 1)
	{
		oldest = 0;
		return (1);
	}
	oldest = 0;
	return (0);
}

void	Contact::newOldest()
{
	oldest = 1;
}

void	Contact::createContact()
{
	if (firstName.empty() == false)
		firstName = "";
	while (firstName.empty())
	{
		std::cout << "Please, enter your first name :" << std::endl;
		std::getline(std::cin, firstName);
	}
	if (lastName.empty() == false)
		lastName = "";
	while (lastName.empty())
	{
		std::cout << "Please, enter your last name :" << std::endl;
		std::getline(std::cin, lastName);
	}
	if (nickname.empty() == false)
		nickname = "";
	while (nickname.empty())
	{
		std::cout << "Please, enter your nickname :" << std::endl;
		std::getline(std::cin, nickname);
	}
	if (phoneNumber.empty() == false)
		phoneNumber = "";
	while (phoneNumber.empty())
	{
		std::cout << "Please, enter your phone number :" << std::endl;
		std::getline(std::cin, phoneNumber);
	}
	if (darkestSecret.empty() == false)
		darkestSecret = "";
	while (darkestSecret.empty())
	{
		std::cout << "Please, enter your darkest secret :" << std::endl;
		std::getline(std::cin, darkestSecret);
	}
}
