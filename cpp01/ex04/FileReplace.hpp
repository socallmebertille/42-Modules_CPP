/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:35:55 by saberton          #+#    #+#             */
/*   Updated: 2025/03/24 16:25:11 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_HPP
# define FILEREPLACE_HPP

# include <fstream>
# include <iostream>

class FileReplace
{
  private:
	std::string const fileOrigin;
	std::string const s1;
	std::string const s2;
	std::string fileReplace;

  public:
	FileReplace(std::string const fileOrigin, std::string const s1,
		std::string const s2);
	~FileReplace();
	void copyInFileReplace(void);
	std::string replace_s1_by_s2(std::string read);
	void displayFileOrigin(void);
	void displayFileReplace(void);
};

#endif