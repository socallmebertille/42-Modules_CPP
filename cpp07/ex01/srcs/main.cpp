/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:09:41 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 16:46:55 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <sstream>

void    functionOnString(std::string& data)
{
    data = data + " check";
}

void    functionOnInt(int& data)
{
    data += 1;
}

int main(void)
{
    int len(4);

    std::cout << "\033[38;5;45m    STRING ARRAY    \033[0m" << std::endl;
    std::string strTab[len];
    std::cout << "\033[38;5;220mBEFORE iter ->\033[0m" << std::endl;
    for (int i(0); i < len; i++)
    {
        std::stringstream ss;
        ss << i;
        strTab[i] = "num : " + ss.str();
        std::cout << strTab[i] << std::endl;
    }
    ::iter(strTab, len, functionOnString);
    std::cout << "\033[38;5;220mAFTER iter ->\033[0m" << std::endl;
    for (int i(0); i < len; i++)
        std::cout << strTab[i] << std::endl;


    std::cout << std::endl << "\033[38;5;45m    INT ARRAY    \033[0m" << std::endl;
    int intTab[len];
    std::cout << "\033[38;5;220mBEFORE iter ->\033[0m" << std::endl;
    for (int i(0); i < len; i++)
    {
        intTab[i] = i;
        std::cout << intTab[i] << std::endl;
    }
    ::iter(intTab, len, functionOnInt);
    std::cout << "\033[38;5;220mAFTER iter ->\033[0m" << std::endl;
    for (int i(0); i < len; i++)
        std::cout << intTab[i] << std::endl;


    std::cout << std::endl << "\033[38;5;45m    ITER WITH PRINT TEMPLATE FUNCTION    \033[0m" << std::endl;
    std::cout << "\033[38;5;220mPRINT string tab ->\033[0m" << std::endl;
    ::iter(strTab, len, ::printWathever);
    std::cout << "\033[38;5;220mPRINT int tab ->\033[0m" << std::endl;
    ::iter(intTab, len, ::printWathever);
    return (0);
}