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

ScalarConverter::ScalarConverter(std::string input)
{
	// std::cout << "ScalarConverter constructor of " << name << " called ..." << std::endl;
}

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

int ScalarConverter::convert(std::string input)
{

}
