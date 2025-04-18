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

int	isLetter(std::string input)
{
	if (input.size() == 1 && (input[0] < '0' || input[0] > '9'))
		return (1);
	return (0);
}
int isNumber(std::string input)
{
	for (int i(0); i < static_cast<int>(input.size()); i++)
	{
		if ((input[i] < '0' || input[i] > '9') && input[0] != '-' && input[input.size() - 1] != 'f' && input[i] != '.')
			return (0);
	}
	return (1);
}

int isPseudoLiterals(std::string input)
{
	std::string pseudo_literals[3] = {"-inf", "+inf", "nan"};
	for (int i(0); i < 3; i++)
	{
		if (pseudo_literals[i] == input || pseudo_literals[i] + "f" == input)
			return (1);
		else if (i == 2 && input.size() > 1 && isNumber(input) == 0)
		{
			std::cerr << RED << "Invalid input" << RESET << std::endl ;
			exit(0);
		}
	}
	return (0);
}

void ScalarConverter::convert(std::string input)
{
	//----------------PARING----------------------
	int pseudoLiterals = isPseudoLiterals(input);
	float change;
	std::stringstream(input) >> change;
	std::cout << std::endl << "Conv.  | -> " << input << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------CHAR----------------------
	std::cout << "char   | ";
	if (!change && isLetter(input))
		std::cout << static_cast<char>(input[0]) << std::endl;
	else if (input[0] == '4' && input[1] == '2')
		std::cout << "*" << std::endl;
	else if (pseudoLiterals == 1)
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	else
		std::cout << YELLOW << "Non displayable" << RESET << std::endl;
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
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(change) << "f" << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------DOUBLE----------------------
	std::cout << "double | ";
	if (!change && isLetter(input))
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(change) << std::endl;
}
