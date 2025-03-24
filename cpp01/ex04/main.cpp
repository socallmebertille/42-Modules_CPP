/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:40:12 by saberton          #+#    #+#             */
/*   Updated: 2025/03/24 16:53:00 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!av[2] || !av[2][0])
			return (std::cerr << "ERROR" << std::endl << "<s1> can't be empty" << std::endl,
				0);
		FileReplace file(av[1], av[2], av[3]);
		std::cout << std::endl;
		if (!file.copyInFileReplace())
			return (0);
		std::cout << std::endl;
		if (!file.displayFileOrigin())
			return (0);
		std::cout << std::endl;
		if (!file.displayFileReplace())
			return (0);
		std::cout << std::endl;
	}
	else
		std::cerr << "Programm must be run with 3 args like :" << std::endl << "    ./fileReplace <filename> <s1> <s2>" << std::endl;
	return (0);
}
