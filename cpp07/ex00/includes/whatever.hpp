/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 00:29:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename whatever> void swap(whatever& a, whatever& b)
{
	whatever	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename whatever> const whatever min(const whatever& a, const whatever& b)
{
	whatever	result;

	result = (a < b) ? a : b;
	return (result);
}
template <typename whatever> const whatever max(const whatever& a, const whatever& b)
{
	whatever	result; 

	result = (a > b) ? a : b;
	return (result);
}

#endif