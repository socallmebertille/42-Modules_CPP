/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/22 00:29:23 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
  private:
	T* _array;
	unsigned int _n;
  public:
	Array();
	Array(unsigned int n);
	Array(const Array& cpy);
	Array& operator=(const Array& cpy);
	~Array();
	T& operator[](unsigned int idx);
	const T& operator[](unsigned int idx) const;
	unsigned int getSize();
};

#endif

////////////// WITHOUT ARRAY_TPP FILE /////////////////////

// #ifndef ARRAY_HPP
// # define ARRAY_HPP

// # include <iostream>
// # include <stdexcept>
//
// template <typename T>
// class Array
// {
//   private:
// 	T* _array;
// 	unsigned int _n;
//   public:
// 	Array():_array(NULL), _n(0) {}
// 	Array(unsigned int n): _array(new T[n]), _n(n) {}
// 	Array(const Array& cpy):_array(NULL), _n(0) { *this = cpy; }
// 	Array& operator=(const Array& cpy)
// 	{
// 		if (this != &cpy)
// 		{
// 			if (_array != NULL)
// 			{
// 				delete [] _array;
// 				_array = NULL;
// 			}
// 			_n = cpy._n;
// 			if (_n > 0)
// 			{// template <class T>
// class Array
// {
//   private:
// 	T* _array;
// 	unsigned int _n;
//   public:
// 	Array():_array(NULL), _n(0) {}
// 	Array(unsigned int n): _array(new T[n]), _n(n) {}
// 	Array(const Array& cpy):_array(NULL), _n(0) { *this = cpy; }
// 	Array& operator=(const Array& cpy)
// 	{
// 		if (this != &cpy)
// 		{
// 			if (_array != NULL)
// 			{
// 				delete [] _array;
// 				_array = NULL;
// 			}
// 			_n = cpy._n;
// 			if (_n > 0)
// 			{
// 				_array = new T[cpy._n];
// 				for (unsigned int i(0); i < _n; i++)
// 					_array[i] = cpy._array[i];
// 			}
// 		}
// 		return (*this);
// 	}
// 	~Array() { if(_array) delete [] _array; }
// 	T& operator[](unsigned int idx)
// 	{
// 		if (idx < _n)
// 			return (this->_array[idx]);
// 		throw (std::out_of_range("Index out of bounds"));
// 	}
// 	const T& operator[](unsigned int idx) const
// 	{
// 		if (idx < _n)
// 			return _array[idx];
// 		throw std::out_of_range("Index out of bounds");
// 	}
// 	unsigned int getSize() { return (_n); }
// };
// 				_array = new T[cpy._n];
// 				for (unsigned int i(0); i < _n; i++)
// 					_array[i] = cpy._array[i];
// 			}
// 		}
// 		return (*this);
// 	}
// 	~Array() { if(_array) delete [] _array; }
// 	T& operator[](unsigned int idx)
// 	{
// 		if (idx < _n)
// 			return (this->_array[idx]);
// 		throw (std::out_of_range("Index out of bounds"));
// 	}
// 	const T& operator[](unsigned int idx) const
// 	{
// 		if (idx < _n)
// 			return _array[idx];
// 		throw std::out_of_range("Index out of bounds");
// 	}
// 	unsigned int getSize() { return (_n); }
// };

// #endif