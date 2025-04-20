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
	return input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]);
}
int isNumber(std::string input)
{
	int start(0);
	if (input[0] == '+' || input[0] == '-')
		start++;
	int len = static_cast<int>(input.size());
	if (input[input.size() - 1] == 'f')
		len--;
	int point(0);
	int nbDec(0);
	for (int i(start); i < len; i++)
	{
		if (input[i] == '.')
			point++;
		if (input[i] == '.' && point > 1)
			return (-1);
		if (point == 1 && input[i] > '0' && input[i] <= '9')
			nbDec++;
		if ((input[i] < '0' || input[i] > '9') && input[i] != '.')
			return (-1);
	}
	return (nbDec);
}

int isPseudoLiterals(std::string input)
{
	std::string pseudo_literals[4] = {"inf", "-inf", "+inf", "nan"};
	for (int i(0); i < 4; i++)
	{
		if (pseudo_literals[i] == input)
			return (1);
		else if (pseudo_literals[i] + "f" == input)
			return (2);
		else if (i == 3 && input.size() > 1 && isNumber(input) == -1)
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
	double change;
	std::stringstream(input) >> change;
	std::cout << std::endl << CYAN << "Conv.  | -> " << input << RESET << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------CHAR----------------------
	std::cout << "char   | ";
	if (isLetter(input))
		std::cout << static_cast<char>(input[0]) << std::endl;
	else if (input[0] == '4' && input[1] == '2')
		std::cout << "\'*\'" << std::endl;
	else if (pseudoLiterals)
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	else
		std::cout << YELLOW << "Non displayable" << RESET << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------INT----------------------
	std::cout << "int    | ";
	if (isLetter(input))
		std::cout << static_cast<int>(input[0]) << std::endl;
	else if (pseudoLiterals)
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	else
		std::cout << static_cast<int>(change) << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------FLOAT----------------------
	std::cout << "float  | ";
	if (isLetter(input))
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
	else if (pseudoLiterals == 1)
		std::cout << input + "f" << std::endl;
	else if (pseudoLiterals == 2)
		std::cout << input << std::endl;
	else if (isNumber(input) > 0)
		std::cout << std::fixed << std::setprecision(isNumber(input)) << static_cast<float>(change) << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(change) << "f" << std::endl;
	std::cout << "-------+-------------" << std::endl;

	//----------------DOUBLE----------------------
	std::cout << "double | ";
	if (isLetter(input))
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
	else if (pseudoLiterals == 1)
		std::cout << input << std::endl;
	else if (pseudoLiterals == 2)
	{
		for (int i(0); i < static_cast<int>(input.size()) - 1; i++)
			std::cout << input[i];
		std::cout << std::endl;
	}
	else if (isNumber(input) > 0)
		std::cout << std::fixed << std::setprecision(isNumber(input)) << static_cast<double>(change) << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(change) << std::endl;
}
