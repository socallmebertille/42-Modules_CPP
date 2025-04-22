/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:01 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 05:10:38 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

Base * generate(void)
{
	srand(time(NULL));
	if (rand() % 3 == 0)
		return (new A());
	else if (rand() % 3 == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Wrong type" << std::endl;
}

void identify(Base& p)
{
	Base tmp;

	try
	{
		tmp = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			tmp = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				tmp = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} 
			catch (std::exception &e)
			{
				std::cerr << "Wrong type" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base* base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
