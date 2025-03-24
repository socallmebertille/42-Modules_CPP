/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:35:58 by saberton          #+#    #+#             */
/*   Updated: 2025/03/24 16:25:05 by saberton         ###   ########.fr       */
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
	std::cout << "Destructor called ..." << std::endl;
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

void FileReplace::copyInFileReplace(void)
{
	std::ifstream originFile(fileOrigin.c_str());
	if (!originFile)
	{
		std::cout << "ERROR" << std::endl << "Can't read " << fileOrigin;
		return ;
	}
	std::ofstream replaceFile(fileReplace.c_str());
	if (!replaceFile)
	{
		std::cout << "ERROR" << std::endl << "Can't open " << fileReplace;
		return ;
	}
	std::cout << "Copying FileOrigin and replace \"" << s1 << "\" by \"" << s2 << "\" ..." << std::endl;
	std::string read;
	while (std::getline(originFile, read))
	{
		replaceFile << replace_s1_by_s2(read) << std::endl;
	}
	std::cout << "Copy & replace of " << fileReplace << " done." << std::endl;
}

void FileReplace::displayFileOrigin(void)
{
	std::ifstream originFile(fileOrigin.c_str());
	if (!originFile)
	{
		std::cout << "ERROR" << std::endl << "Can't read " << fileOrigin;
		return ;
	}
	std::cout << "Displaying FileOrigin : " << std::endl << std::endl;
	std::string read;
	while (std::getline(originFile, read))
		std::cout << read << std::endl;
}

void FileReplace::displayFileReplace(void)
{
	std::ifstream replaceFile(fileReplace.c_str());
	if (!replaceFile)
	{
		std::cout << "ERROR" << std::endl << "Can't read " << fileReplace;
		return ;
	}
	std::cout << "Displaying FileReplace : " << std::endl << std::endl;
	std::string read;
	while (std::getline(replaceFile, read))
		std::cout << read << std::endl;
}
