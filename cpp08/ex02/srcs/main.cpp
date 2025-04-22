/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:47:12 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 21:57:32 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../includes/Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    try
	{
		std::cout << "\033[38;5;45m    DEFAULT TEST    \033[0m" << std::endl;
		Array<int> emptyArray;
		std::cout << "\033[38;5;220mWith empty array ->\033[0m" << std::endl;
		std::cout << "Array getSize : " << emptyArray.getSize() << std::endl;
		Array<int> intArray(5);
		std::cout << "\033[38;5;220mWith getSize ->\033[0m" << std::endl;
		std::cout << "Array getSize : " << intArray.getSize() << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
		{
			intArray[i] = i * 10;
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;
		}

		std::cout << std::endl << "\033[38;5;45m    COPY TEST    \033[0m" << std::endl;
		Array<int> copiedArray(intArray);
		copiedArray[0] = 42;
		std::cout << "\033[38;5;220mOriginal ->\033[0m" << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;
		std::cout << "\033[38;5;220mCopy ->\033[0m" << std::endl;
		for (unsigned int i = 0; i < copiedArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << copiedArray[i] << std::endl;

		std::cout << std::endl << "\033[38;5;45m    COPY ASSIGMENT TEST    \033[0m" << std::endl;
		Array<int> assignedArray;
		assignedArray = intArray;
		std::cout << "\033[38;5;220mOriginal ->\033[0m" << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;
		assignedArray[4] = 42;
		std::cout << "\033[38;5;220mAssigment ->\033[0m" << std::endl;
		for (unsigned int i = 0; i < assignedArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << assignedArray[i] << std::endl;

		std::cout << std::endl << "\033[38;5;45m    OUT OF BOUNDS TEST    \033[0m" << std::endl;
		std::cout << "\033[38;5;220mgetSize of array[" << intArray.getSize() << "] ->\033[0m trying to access index 10 " << std::endl;
		std::cout << intArray[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << std::endl << std::endl;
	}
    return (0);
}