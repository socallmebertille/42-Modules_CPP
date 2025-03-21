/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:57:36 by saberton          #+#    #+#             */
/*   Updated: 2025/03/21 17:13:11 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
  public:
	Contact();
	// ~Contact();
	void		createContact();
	void		displayContact();
	void		newOldest();
	int			getOldest();
	std::string	displayFirstName();
	std::string	displayLastName();
	std::string	displayNickname();
  private:
	int			oldest;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif