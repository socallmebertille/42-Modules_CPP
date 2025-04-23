/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 00:29:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <sstream>

template <typename T> void easyfind(const T& container, const int toFind)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
	{
		std::stringstream ss;
		ss << toFind;
		throw(std::runtime_error("Occurence of [" + ss.str() + "] not found"));
	}
	std::cout << "Occurence of [" << toFind << "] find at index[" << std::distance(container.begin(), it) << "]" << std::endl;
}

#endif