/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:56:40 by saberton          #+#    #+#             */
/*   Updated: 2025/03/19 17:00:53 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	str_to_upper(char **str)
{
	for (int i(0); str[i]; i++)
	{
		for (int j(0); str[i][j]; j++)
		{
			char	c(str[i][j]);
			c = std::toupper(c);
			std::cout << c;
		}
	}
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		str_to_upper(av + 1);
	return (0);
}
