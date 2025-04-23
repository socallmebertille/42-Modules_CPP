/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 00:29:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T> void iter(T* array, int lenArray, void (*f)(T&))
{
	for (int i(0); i < lenArray; i++)
		f(array[i]);
}

template <typename T> void iter(const T* array, int lenArray, void (*f)(const T&))
{
	for (int i(0); i < lenArray; i++)
		f(array[i]);
}

template <typename T> void printWathever(const T& array)
{
	std::cout << array << std::endl;
}

#endif