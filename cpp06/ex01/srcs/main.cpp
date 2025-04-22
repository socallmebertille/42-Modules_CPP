/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 02:32:07 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.value = 42;
	data.name = "Hola que tal";

	std::cout << "Original data address    : " << &data << std::endl;
	std::cout << "Original data value      : " << data.value << std::endl;
	std::cout << "Original data name       : " << data.name << std::endl << std::endl;

	// Sérialisation
	uintptr_t raw = Serializer::serialize(&data);

	// Désérialisation
	Data* newPtr = Serializer::deserialize(raw);
	
	std::cout << "Deserialaze data address : " << &newPtr << std::endl;
	std::cout << "Deserialaze data value   : " << newPtr->value << std::endl;
	std::cout << "Deserialaze data string  : " << newPtr->name << std::endl << std::endl;

	if (newPtr == &data)
		std::cout << GREEN << "SUCCESS                  : The pointers are the same!" << RESET << std::endl;
	else
		std::cout << RED << "ERROR                    : The pointers differ!" << RESET << std::endl;
	return (0);
}
