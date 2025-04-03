/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:00:21 by saberton          #+#    #+#             */
/*   Updated: 2025/04/03 19:48:03 by saberton         ###   ########.fr       */
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
	ICharacter* me = new Character("me");
	
	std::cout << std::endl << "\033[38;5;45mInstances tests\033[0m" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "\033[38;5;45mInstances delete\033[0m" << std::endl;
	delete bob;
	delete me;
	delete src;

	// ./Interface | cat -e should display :
	// * shoots an ice bolt at bob *$
	// * heals bob's wounds *$
	return (0);
}
