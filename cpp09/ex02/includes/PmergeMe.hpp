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
# include <vector>
# include <list>

class PmergeMe
{
  private:
	
  public:
	PmergeMe();
	PmergeMe(const PmergeMe& cpy);
	PmergeMe& operator=(const PmergeMe& cpy);
	~PmergeMe();
};


#endif