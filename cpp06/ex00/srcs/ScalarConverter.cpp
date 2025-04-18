/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:59 by saberton          #+#    #+#             */
/*   Updated: 2025/04/16 16:24:24 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) { *this = cpy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cpy)
{
	(void)cpy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

int	isLetter(std::string letter)
{
	if (letter.size() == 1 && (letter[0] < '0' || letter[0] > '9'))
		return (1);
	return (0);
}

void ScalarConverter::convert(std::string input)
{
	//----------------PARING----------------------
	std::stringstream ss(input);
	int change;
	if (!(ss >> change))
	{
		std::string pseudo_literals[3] = {"-inf", "+inf", "nan"};
		for (int i(0); i < 3; i++)
		{
			if (pseudo_literals[i] == input || pseudo_literals[i] + "f" == input)
				break ;
			else if (i == 2 && input.size() > 1)
			{
				std::cout << RED << "Invalid input" << RESET << std::endl ;
				return ;
			}
		}

	}

	std::cout << std::endl << "Conv.  | -> " << input << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------CHAR----------------------
	std::cout << "char   | ";
	if (!change)
		std::cout << input.c_str() << std::endl;
	else
		std::cout << YELLOW << "No convertable :(" << RESET << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------INT----------------------
	std::cout << "int    | ";
	if (!change && isLetter(input))
		std::cout << static_cast<int>(input[0]) << std::endl;
	else
		std::cout << static_cast<int>(change) << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------FLOAT----------------------
	std::cout << "float  | ";
	if (!change && isLetter(input))
		std::cout << static_cast<float>(input[0]) << std::endl;
	else
		std::cout << static_cast<float>(change) << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------DOUBLE----------------------
	std::cout << "double | ";
	if (!change && isLetter(input))
		std::cout << static_cast<double>(input[0]) << std::endl;
	else
		std::cout << static_cast<double>(change) << std::endl;
}
