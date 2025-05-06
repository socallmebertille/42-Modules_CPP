/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:48:08 by bertille          #+#    #+#             */
/*   Updated: 2025/05/01 23:03:24 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <stdexcept>
# include <algorithm>
# include <iterator>
# include <vector>
# include <deque>
# include <list>
# include <ctime>

# define GREEN   "\033[32m"
# define YELLOW  "\033[38;5;220m"
# define PINK    "\033[38;5;213m"
# define CYAN    "\033[38;5;45m"
# define RED     "\e[1;91m"
# define BOLD    "\033[1m"
# define RESET   "\033[0m"

class PmergeMe
{
  private:
	std::deque<int> _d;
	std::list<int> _l;
	float sortDeque(void);
	float sortList(void);
	// std::deque<int> fordJohnsonDeque(std::deque<int> input);
	// std::list<int> fordJohnsonList(std::list<int> input);
  public:
	PmergeMe();
	PmergeMe(const PmergeMe& cpy);
	PmergeMe& operator=(const PmergeMe& cpy);
	~PmergeMe();
	void initElems(const std::string elems);
	void printDeque(void) const;
	void printList(void) const;
	void sortAlgo(void);
};


#endif