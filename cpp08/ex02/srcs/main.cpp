/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:47:12 by saberton          #+#    #+#             */
/*   Updated: 2025/04/28 19:19:50 by bertille         ###   ########.fr       */
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
	std::cout << std::endl << CYAN << " ---- My tests ---- " << RESET << std::endl;

	cont.push(5);
	cont.push(17);
	std::cout << GREEN << "Size before pop: " << cont.size() << RESET << std::endl;
	std::cout << YELLOW << "Elmts at the top: " << cont.top() << RESET << std::endl; //top retourne dernier elmts pope

	cont.pop(); //supprime elmt haut de la pile
	std::cout << std::endl << GREEN << "Size after pop: " << cont.size() << RESET << std::endl;

	cont.push(3);
	cont.push(5);
	cont.push(737);
	cont.push(0);

	typename Container::iterator it  = cont.begin();
	typename Container::iterator ite = cont.end();

	std::cout << WHITE << "print after adds elmts:" << RESET << std::endl;
	++it;
	--it;
	for (; it != ite; ++it)
		std::cout << CYAN << *it << RESET << std::endl;

	std::cout << std::endl << CYAN << "Reverse " << RESET << std::endl;
	typename Container::reverse_iterator rit  = cont.rbegin();
	typename Container::reverse_iterator rite = cont.rend();
	for (; rit != rite; ++rit)
	std::cout << CYAN << *rit << RESET << std::endl;

	std::cout << std::endl << CYAN << "Modifying elements through iterator (add 10):" << RESET << std::endl;
	for (it = cont.begin(); it != cont.end(); ++it)
		*it += 10;

	std::cout << WHITE << "Elements after modification:" << RESET << std::endl;
	for (it = cont.begin(); it != cont.end(); ++it)
		std::cout << CYAN << *it << RESET << std::endl;

	std::cout << std::endl << GREEN << "Size after modifications: " << cont.size() << RESET << std::endl;
	Container copy = cont;
	std::cout << GREEN << "Copied container size: " << copy.size() << RESET << std::endl;

	std::cout << WHITE << "Elements in copied container:" << RESET << std::endl;
	for (it = copy.begin(); it != copy.end(); ++it)
		std::cout << CYAN << *it << RESET << std::endl;
}

int main()
{
	std::cout << ">>> Test with MutantStack <<<" << std::endl;
	MutantStack<int> ms;
	myTest(ms);

	std::cout << "\n>>> Test with std::list (via ListAdapter) <<<" << std::endl;
	ListAdapter lst;
	myTest(lst);

	std::cout << "\n>>> Test with std::vector (via VectorAdapter) <<<" << std::endl;
	VectorAdapter vect;
	myTest(vect);

	return 0;
}