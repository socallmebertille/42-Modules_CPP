/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:35:58 by saberton          #+#    #+#             */
/*   Updated: 2025/03/24 17:03:49 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"

FileReplace::FileReplace(std::string const fileOrigin, std::string const s1,
	std::string const s2) : fileOrigin(fileOrigin), s1(s1), s2(s2),
	fileReplace(fileOrigin + ".replace")
{
	std::cout << "Contructor called ..." << std::endl;
	std::cout << fileReplace << " created" << std::endl;
}

FileReplace::~FileReplace()
{
	std::cout << std::endl << "Destructor called ..." << std::endl;
}

std::string FileReplace::replace_s1_by_s2(std::string read)
{
	std::size_t pos = read.find(s1);
	if (pos == std::string::npos)
		return (read);
	while (read[pos])
	{
		pos = read.find(s1, pos);
		if (pos != std::string::npos)
		{
			read.erase(pos, s1.size());
			read.insert(pos, s2);
			pos += s2.size();
		}
		else
			break ;
	}
	return (read);
}

int FileReplace::copyInFileReplace(void)
{
	std::ifstream originFile(fileOrigin.c_str());
	if (!originFile)
	{
		std::cerr << "ERROR" << std::endl << "Can't read " << fileOrigin << std::endl;
		return (0);
	}
	std::ofstream replaceFile(fileReplace.c_str());
	if (!replaceFile)
	{
		std::cerr << "ERROR" << std::endl << "Can't open " << fileReplace << std::endl;
		return (0);
	}
	std::cout << "Copying FileOrigin and replace \"" << s1 << "\" by \"" << s2 << "\" ..." << std::endl;
	std::string read;
	if (s1 == s2)
		std::cout << "<s1> and <s2> are identical, no replacement needed" << std::endl;
	while (std::getline(originFile, read))
	{
		if (s1 == s2)
			replaceFile << read << std::endl;
		else
			replaceFile << replace_s1_by_s2(read) << std::endl;
	}
	if (s1 == s2)
		std::cout << "Copy of " << fileReplace << " done." << std::endl;
	else
		std::cout << "Copy & replace of " << fileReplace << " done." << std::endl;
	return (1);
}

int FileReplace::displayFileOrigin(void)
{
	std::ifstream originFile(fileOrigin.c_str());
	if (!originFile)
	{
		std::cerr << "ERROR" << std::endl << "Can't read " << fileOrigin << std::endl;
		return (0);
	}
	std::cout << "Displaying FileOrigin : " << std::endl << std::endl;
	std::string read;
	while (std::getline(originFile, read))
		std::cout << read << std::endl;
	return (1);
}

int FileReplace::displayFileReplace(void)
{
	std::ifstream replaceFile(fileReplace.c_str());
	if (!replaceFile)
	{
		std::cerr << "ERROR" << std::endl << "Can't read " << fileReplace << std::endl;
		return (0);
	}
	std::cout << "Displaying FileReplace : " << std::endl << std::endl;
	std::string read;
	while (std::getline(replaceFile, read))
		std::cout << read << std::endl;
	return (1);
}
