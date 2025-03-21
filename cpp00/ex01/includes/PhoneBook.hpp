/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:57:44 by saberton          #+#    #+#             */
/*   Updated: 2025/03/21 15:46:02 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
  public:
	// PhoneBook();
	// ~PhoneBook();
	void	add();
	void	search();
	void	exit();
  private:
	Contact	phoneBook[8];
	int		nbContact;
};

#endif