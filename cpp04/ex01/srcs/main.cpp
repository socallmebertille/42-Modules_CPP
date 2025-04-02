/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:00:21 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 00:22:52 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\033[38;5;220m========= Animals tests subject ==============\033[0m" << std::endl;
	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* newCat = new Cat(dynamic_cast<const Cat&>(*i));
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
	Animal* AnimalArr[ArrLen];
	for (int i(0); i < ArrLen / 2; i++)
		AnimalArr[i] = new Dog();
	for (int i(ArrLen / 2); i < ArrLen; i++)
		AnimalArr[i] = new Cat();
	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	std::cout << AnimalArr[ArrLen / 2 - 1]->getType() << " -> ";
	AnimalArr[ArrLen / 2 - 1]->makeSound();
	if (dynamic_cast<const Dog*>(AnimalArr[ArrLen / 2 - 1]))
		dynamic_cast<const Dog*>(AnimalArr[ArrLen / 2 - 1])->getIdeas(5, 1);
	std::cout << AnimalArr[ArrLen / 2]->getType() << " -> ";
	AnimalArr[ArrLen / 2]->makeSound();
	if (dynamic_cast<const Cat*>(AnimalArr[ArrLen / 2]))
		dynamic_cast<const Cat*>(AnimalArr[ArrLen / 2])->getIdeas(5, 2);
	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	for (int i(0); i < ArrLen; i++)
		delete AnimalArr[i];

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
