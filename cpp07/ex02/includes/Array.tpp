/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:04:13 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 22:08:51 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>Array<T>::Array():_array(NULL), _n(0) {}

template <typename T>Array<T>::Array(unsigned int n): _array(new T[n]), _n(n) {}

template <typename T>Array<T>::Array(const Array& cpy):_array(NULL), _n(0) { *this = cpy; }

template <typename T> Array<T>& Array<T>::operator=(const Array& cpy)
{
    if (this != &cpy)
    {
        if (_array != NULL)
        {
            delete [] _array;
            _array = NULL;
        }
        _n = cpy._n;
        if (_n > 0)
        {
            _array = new T[cpy._n];
            for (unsigned int i(0); i < _n; i++)
                _array[i] = cpy._array[i];
        }
    }
    return (*this);
}

template <typename T> Array<T>::~Array() { if(_array) delete [] _array; }

template <typename T> T& Array<T>::operator[](unsigned int idx)
{
    if (idx < _n)
        return (this->_array[idx]);
    throw (std::out_of_range("Index out of bounds"));
}

template <typename T> const T& Array<T>::operator[](unsigned int idx) const
{
    if (idx < _n)
        return _array[idx];
    throw std::out_of_range("Index out of bounds");
}

template <typename T> unsigned int Array<T>::getSize() { return (_n); }
