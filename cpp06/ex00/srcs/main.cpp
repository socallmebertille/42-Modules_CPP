/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/18 19:46:29 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
	}
	return (0);
}

// int	main(void)
// {
// 	std::cout << "\033[38;5;45m==========Scalar converter tests==========\033[0m" << std::endl;
// 	try
// 	{
// 		ScalarConverter res;
		
// 		std::cout << "\033[38;5;220mChar tests : \033[0m" << std::endl;
// 		res.convert("a");
	
// 		std::cout << std::endl << "\033[38;5;220mInt tests : \033[0m" << std::endl;
// 		res.convert("-42");
// 		res.convert("0");
// 		res.convert("42");
		
// 		std::cout << std::endl << "\033[38;5;220mFloat tests : \033[0m" << std::endl;
// 		res.convert("0.0f");
// 		res.convert("-4.2f");
// 		res.convert("4.2f");
// 		res.convert("42.0f");
		
// 		std::cout << std::endl << "\033[38;5;220mDecimal tests : \033[0m" << std::endl;
// 		res.convert("0.0");
// 		res.convert("-4.2");
// 		res.convert("4.2");
// 		res.convert("3.14");
		
// 		std::cout << std::endl << "\033[38;5;220mPseudo-literals tests : \033[0m" << std::endl;
// 		res.convert("-inff");
// 		res.convert("+inff");
// 		res.convert("nanf");

// 		std::cout << std::endl << "\033[38;5;220mString tests : \033[0m" << std::endl;
// 		res.convert("bonjour");
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "Error : " << e.what() << std::endl;
// 	}
// 	return (0);
// }