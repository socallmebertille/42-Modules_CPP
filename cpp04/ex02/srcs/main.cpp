/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:00:21 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 11:46:17 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// AAnimal test;
	// test.makeSound();
	// AAnimal* test = new AAnimal();
	// test->makeSound();
	// std::cout << std::endl;

	std::cout << "\033[38;5;220m========= Animals tests subject ==============\033[0m" << std::endl;
	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	const AAnimal* newCat = new Cat(dynamic_cast<const Cat&>(*i));
	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	std::cout << j->getType() << " -> ";
	j->makeSound();
	if (dynamic_cast<const Dog*>(j))
		dynamic_cast<const Dog*>(j)->getIdeas(0, 4);
	std::cout << i->getType() << " -> ";
	i->makeSound(); //will output the cat sound!
	if (dynamic_cast<const Cat*>(i))
		dynamic_cast<const Cat*>(i)->getIdeas(0, 4);
	std::cout << newCat->getType() << " -> ";
	newCat->makeSound();
	if (dynamic_cast<const Cat*>(newCat))
		dynamic_cast<const Cat*>(newCat)->getIdeas(2, 4);
	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	delete j; //should not create a leak
	delete i;
	delete newCat;

	std::cout << std::endl << "\033[38;5;220m========= Array of animal ==============\033[0m" << std::endl;
	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;
	const int ArrLen(4);
	AAnimal* AAnimalArr[ArrLen];
	for (int i(0); i < ArrLen / 2; i++)
		AAnimalArr[i] = new Dog();
	for (int i(ArrLen / 2); i < ArrLen; i++)
		AAnimalArr[i] = new Cat();
	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	std::cout << AAnimalArr[ArrLen / 2 - 1]->getType() << " -> ";
	AAnimalArr[ArrLen / 2 - 1]->makeSound();
	if (dynamic_cast<const Dog*>(AAnimalArr[ArrLen / 2 - 1]))
		dynamic_cast<const Dog*>(AAnimalArr[ArrLen / 2 - 1])->getIdeas(5, 1);
	std::cout << AAnimalArr[ArrLen / 2]->getType() << " -> ";
	AAnimalArr[ArrLen / 2]->makeSound();
	if (dynamic_cast<const Cat*>(AAnimalArr[ArrLen / 2]))
		dynamic_cast<const Cat*>(AAnimalArr[ArrLen / 2])->getIdeas(5, 2);
	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	for (int i(0); i < ArrLen; i++)
		delete AAnimalArr[i];

	std::cout << std::endl << "\033[38;5;220m========= Testing copy dog with new ==============\033[0m" << std::endl;
	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;
	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog(*dog1);
	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	std::cout << dog2->getType() << " -> ";
	dog2->makeSound();
	dog2->getIdeas(87, 1);
	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	delete dog1;
	delete dog2;

	std::cout << std::endl << "\033[38;5;220m========= Testing copy cat without new ==============\033[0m" << std::endl;
	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;
	Cat catcat;
	Cat catca = catcat;
	catca = catcat;
	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	std::cout << catca.getType() << " -> ";
	catca.makeSound();
	catca.getIdeas(99, 1);
	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	return (0);
}
