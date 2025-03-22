/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:40:32 by bertille          #+#    #+#             */
/*   Updated: 2025/03/22 17:33:22 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		str("HI THIS IS BRAIN");
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	std::cout << "Memory adresses : " << std::endl;
	std::cout << "The memory address of the string variable -> " << &str << std::endl;
	std::cout << "The memory address held by stringPTR      -> " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF      -> " << &stringREF << std::endl;
	std::cout << "Values : " << std::endl;
	std::cout << "The value of the string variable          -> " << str << std::endl;
	std::cout << "The value pointed to by stringPTR         -> " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         -> " << stringREF << std::endl;
	return (0);
}
