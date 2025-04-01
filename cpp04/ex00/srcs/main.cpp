/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:00:21 by saberton          #+#    #+#             */
/*   Updated: 2025/04/01 17:05:11 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;
	std::cout << "\033[32m		with virtual :\033[0m" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\033[31m		without virtual :\033[0m" << std::endl;
	const WrongAnimal* wrongA = new WrongAnimal();
	const WrongAnimal* wrongC = new WrongCat();

	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	std::cout << "\033[32m		with virtual :\033[0m" << std::endl;
	std::cout << j->getType() << " -> ";
	j->makeSound();
	std::cout << i->getType() << " -> ";
	i->makeSound(); //will output the cat sound!
	std::cout << meta->getType() << " -> ";
	meta->makeSound();
	std::cout << "\033[31m		without virtual :\033[0m" << std::endl;
	std::cout << wrongA->getType() << " -> ";
	wrongA->makeSound();
	std::cout << wrongC->getType() << " -> ";
	wrongC->makeSound();

	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	std::cout << "\033[32m		with virtual :\033[0m" << std::endl;
	delete i;
	delete j;
	delete meta;
	std::cout << "\033[31m		without virtual :\033[0m" << std::endl;
	delete wrongA;
	delete wrongC;
	return (0);
}
