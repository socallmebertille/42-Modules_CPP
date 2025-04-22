/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:47:12 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 19:01:49 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../includes/Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;
    try
	{
		// default
		Array<int> emptyArray;
		std::cout << std::endl << "Test 0 : default with empty array" << std::endl;
		std::cout << "Array getSize : " << emptyArray.getSize() << std::endl;
		std::cout << "--------------------" << std::endl;

		// with getSize
		Array<int> intArray(5);
		std::cout << "Test 1 : default with getSize" << std::endl;
		std::cout << "Array getSize : " << intArray.getSize() << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
		{
			intArray[i] = i * 10;
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;
		}
		// int* a = new int();
		// std::cout << "Value of *a : " << *a << std::endl;
		// delete a;
		std::cout << "--------------------" << std::endl;

		// copy
		Array<int> copiedArray(intArray);
		copiedArray[0] = 42;

		std::cout << "Test 2 : copy" << std::endl;
		std::cout << "Original :" << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;

		std::cout << std::endl << "Copied :" << std::endl;
		for (unsigned int i = 0; i < copiedArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << copiedArray[i] << std::endl;
		std::cout << "--------------------" << std::endl;

		// assigned
		Array<int> assignedArray;
		assignedArray = intArray;

		std::cout << "Test 3 : assigned" << std::endl;
		std::cout << "Original :" << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << intArray[i] << std::endl;

		assignedArray[4] = 42;
		std::cout << std::endl << "Assigned :" << std::endl;
		for (unsigned int i = 0; i < assignedArray.getSize(); ++i)
			std::cout << "index[" << i << "] = " << assignedArray[i] << std::endl;
		std::cout << "--------------------" << std::endl;

		// out of bounds
		std::cout << "Test 4 : out of bounds" << std::endl;
		std::cout << "getSize of array " << intArray.getSize() << ", trying to access index 10" << std::endl;
		std::cout << intArray[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << std::endl << std::endl;
	}
    return (0);
}