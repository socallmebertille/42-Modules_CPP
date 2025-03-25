/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:51:07 by saberton          #+#    #+#             */
/*   Updated: 2025/03/25 17:01:07 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int _fixedPoint;
	static int _fractionalBits;

  public:
	Fixed();
	Fixed(const Fixed &cpy);
	Fixed &operator=(const Fixed &cpy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif