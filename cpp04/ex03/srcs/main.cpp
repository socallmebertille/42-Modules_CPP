/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:00:21 by saberton          #+#    #+#             */
/*   Updated: 2025/04/04 16:40:36 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "\033[38;5;220m========= Main subject ==============\033[0m" << std::endl;

	std::cout << "\033[38;5;45mInstances init\033[0m" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	
	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	src->learnMateria(new Ice());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	src->learnMateria(new Cure());
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(5, *bob);

	std::cout << std::endl << "\033[38;5;45mInstances copies tests\033[0m" << std::endl;
	
	IMateriaSource* srcM = new MateriaSource();
	if (dynamic_cast<MateriaSource*>(srcM)) {
		MateriaSource* originalM = dynamic_cast<MateriaSource*>(srcM);
		MateriaSource* copyM = new MateriaSource(*originalM);
		ICharacter* meM = new Character("meM");
		std::cout << std::endl;
		
		AMateria* tmpM;
		originalM->learnMateria(new Ice());
		std::cout << std::endl;
		
		tmpM = originalM->createMateria("ice");
		std::cout << std::endl;
		
		meM->equip(tmpM);
		std::cout << std::endl;
		
		originalM->learnMateria(new Cure());
		tmpM = originalM->createMateria("cure");
		meM->equip(tmpM);
		meM->use(0, *bob);
		meM->use(1, *bob);
		meM->use(2, *bob);
		delete copyM;
		delete meM;
	}
	delete srcM;
	
	std::cout << std::endl;
	
	if (dynamic_cast<Character*>(me)) {
		Character* originalC = dynamic_cast<Character*>(me);
		Character* copyC = new Character(*originalC);

		std::cout << "Original character '" << originalC->getName() << "' uses materias:" << std::endl;
		for (int i = 0; i < 4; i++)
			originalC->use(i, *bob);

		std::cout << "Copied character '" << copyC->getName() << "' uses materias:" << std::endl;
		for (int i = 0; i < 4; i++)
			copyC->use(i, *bob);
		delete copyC;
	}
	
	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;

	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	return (0);
}
