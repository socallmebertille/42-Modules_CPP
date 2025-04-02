/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:00:21 by saberton          #+#    #+#             */
/*   Updated: 2025/04/02 15:08:04 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const int ArrLen(4);
	Animal* AnimalArr[ArrLen];
	for (int i(0); i < ArrLen / 2; i++)
		AnimalArr[i] = new Dog();
	for (int i(ArrLen / 2); i < ArrLen; i++)
		AnimalArr[i] = new Cat();

	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	std::cout << j->getType() << " -> ";
	j->makeSound();
	if (dynamic_cast<const Dog*>(j))
		dynamic_cast<const Dog*>(j)->getIdeas(0, 4);
	std::cout << i->getType() << " -> ";
	i->makeSound(); //will output the cat sound!
	if (dynamic_cast<const Cat*>(i))
		dynamic_cast<const Cat*>(i)->getIdeas(0, 4);
	const Animal* newCat(i);
	std::cout << newCat->getType() << " -> ";
	newCat->makeSound();
	if (dynamic_cast<const Cat*>(newCat))
		dynamic_cast<const Cat*>(newCat)->getIdeas(2, 4);
	std::cout << AnimalArr[ArrLen / 2 - 1]->getType() << " -> ";
	AnimalArr[ArrLen / 2 - 1]->makeSound();
	if (dynamic_cast<const Dog*>(AnimalArr[ArrLen / 2 - 1]))
		dynamic_cast<const Dog*>(AnimalArr[ArrLen / 2 - 1])->getIdeas(5, 2);
	std::cout << AnimalArr[ArrLen / 2]->getType() << " -> ";
	AnimalArr[ArrLen / 2]->makeSound();
	if (dynamic_cast<const Cat*>(AnimalArr[ArrLen / 2]))
		dynamic_cast<const Cat*>(AnimalArr[ArrLen / 2])->getIdeas(5, 2);
	

	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	delete j; //should not create a leak
	delete i;
	// delete newCat;
	for (int i(0); i < ArrLen; i++)
		delete AnimalArr[i];


	std::cout << std::endl << "\033[38;5;45mInstances copy tests\033[0m" << std::endl;
	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat(*cat1);

	cat2->makeSound();
	cat2->getIdeas(0, 4);

	delete cat1;
	delete cat2;

	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog(*dog1);

	dog2->makeSound();

	delete dog1;
	delete dog2;

	return (0);
}
