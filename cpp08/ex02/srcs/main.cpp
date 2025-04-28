/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:47:12 by saberton          #+#    #+#             */
/*   Updated: 2025/04/28 20:10:04 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "MutantStack.hpp"

#include <list>
#include <vector>

#define WHITE   "\033[0;37m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[38;5;220m"
#define CYAN    "\033[38;5;45m"
#define RESET   "\033[0m"

struct ListAdapter : public std::list<int> {
	void push(int v) { this->push_back(v); }
	void pop() { this->pop_back(); }
	int& top() { return this->back(); }
	const int& top() const { return this->back(); }
};

struct VectorAdapter : public std::vector<int> {
	void push(int v) { this->push_back(v); }
	void pop() { this->pop_back(); }
	int& top() { return this->back(); }
	const int& top() const { return this->back(); }
};

template <typename Container>
void myTest(Container& cont)
{
	cont.push(5);
	cont.push(17);
	std::cout << "Elems at the top [" << cont.top() << "]" << std::endl; //top retourne dernier elmts pope
	
	std::cout << std::endl << "Size BEFORE pop [" << cont.size() << "]" << std::endl;
	cont.pop(); //supprime elmt haut de la pile
	std::cout << "Size AFTER pop [" << cont.size() << "]" << std::endl;

	cont.push(3);
	cont.push(5);
	cont.push(737);
	cont.push(0);

	typename Container::iterator it  = cont.begin();
	typename Container::iterator ite = cont.end();

	std::cout << std::endl << YELLOW << "AFTER add elems :" << RESET << std::endl;
	++it;
	--it;
	for (; it != ite; ++it)
		std::cout << "[" << *it << "]" << std::endl;

	std::cout << std::endl << YELLOW << "REVERSE : " << RESET << std::endl;
	typename Container::reverse_iterator rit  = cont.rbegin();
	typename Container::reverse_iterator rite = cont.rend();
	for (; rit != rite; ++rit)
		std::cout << "[" << *rit << "]" << std::endl;

	std::cout << std::endl << YELLOW << "Modifying elements through iterator (add 10):" << RESET << std::endl;
	for (it = cont.begin(); it != cont.end(); ++it)
		*it += 10;

	for (it = cont.begin(); it != cont.end(); ++it)
		std::cout << "[" << *it << "]" << std::endl;

	std::cout << "Size AFTER modif [" << cont.size() << "]" << std::endl;

	Container copy = cont;
	std::cout << std::endl << "Copied container size [" << copy.size() << "]" << std::endl;

	std::cout << YELLOW << "COPY : " << RESET << std::endl;
	for (it = copy.begin(); it != copy.end(); ++it)
		std::cout << "[" << *it << "]" << std::endl;
}

int main()
{
	std::cout << CYAN << "    MUTANTSTACK   " << RESET << std::endl << std::endl;
	MutantStack<int> ms;
	myTest(ms);

	std::cout << std::endl << CYAN << "----------------------------------------" << RESET << std::endl;
	
	std::cout << std::endl << CYAN << "    STD::LIST   " << RESET << std::endl << std::endl;
	ListAdapter lst;
	myTest(lst);

	std::cout << std::endl << CYAN << "----------------------------------------" << RESET << std::endl;
	
	std::cout << std::endl << CYAN << "    STD::VECTOR   " << RESET << std::endl << std::endl;
	VectorAdapter vect;
	myTest(vect);

	return 0;
}