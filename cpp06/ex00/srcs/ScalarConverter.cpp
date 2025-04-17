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

ScalarConverter::ScalarConverter()
{
	// std::cout << "ScalarConverter default constructor called ..." << std::endl;
}

// ScalarConverter::ScalarConverter(std::string input)
// {
// 	// std::cout << "ScalarConverter constructor of " << name << " called ..." << std::endl;
// }

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
	// std::cout << "ScalarConverter copy constructor of " << cpy._name << " called ..." << std::endl;
	*this = cpy;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cpy)
{
	// std::cout << "ScalarConverter copy assigment operator of " << cpy._name << " called ..." << std::endl;
	if (this != &cpy)
	{
		
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "ScalarConverter deconstructor of " << _name << " called." << std::endl;
}
# include <sstream>
void ScalarConverter::convert(std::string input)
{

	// if (static_cast<char>(input))

	std::cout << std::endl << "Conversion for ---> " << input << std::endl;
	std::cout << "char   | ";
	std::cout << "  " << input.c_str() << std::endl;
	std::cout << "-------|-----------" << std::endl;
	std::cout << "int    | ";
	int myInt;
	if (std::istringstream(input) >> myInt)
		std::cout << myInt << std::endl;
	else
		std::cout << "no convert :(" << std::endl;
	std::cout << "-------|-----------" << std::endl;
	std::cout << "float  | ";
	std::cout << input.c_str() << std::endl;
	std::cout << "-------|-----------" << std::endl;
	std::cout << "double | ";
	std::cout << input.c_str() << std::endl;
}
