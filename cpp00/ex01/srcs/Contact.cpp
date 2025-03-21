/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:57:14 by saberton          #+#    #+#             */
/*   Updated: 2025/03/21 15:45:29 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Contact::Contact()
// {
	
// }

// Contact::~Contact()
// {
	
// }

void	Contact::displayContact()
{
	std::cout << "First Name : " + firstName << std::endl;
	std::cout << "Last Name : " + firstName << std::endl;
	std::cout << "Nickname : " + firstName << std::endl;
	std::cout << "Phone Number : " + firstName << std::endl;
	std::cout << "Darkest Secret : " + firstName << std::endl;
}

std::string Contact::displayFirstName()
{
	if (firstName.size() == 10)
		return (firstName);
	else if (firstName.size() < 10)
	{
		std::string	remain("");
		while ((firstName + remain).size() < 10)
			remain = remain + " ";
		return (firstName + remain);
	}
	return (firstName.substr(0, 9) + ".");
}

std::string Contact::displayLastName()
{
	if (lastName.size() == 10)
		return (lastName);
	else if (lastName.size() < 10)
	{
		std::string	remain("");
		while ((lastName + remain).size() < 10)
			remain = remain + " ";
		return (lastName + remain);
	}
	return (lastName.substr(0, 9) + ".");
}

std::string Contact::displayNickname()
{
	if (nickname.size() == 10)
		return (nickname);
	else if (nickname.size() < 10)
	{
		std::string	remain("");
		while ((nickname + remain).size() < 10)
			remain = remain + " ";
		return (nickname + remain);
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
