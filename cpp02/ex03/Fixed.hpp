/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:51:07 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 18:32:51 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
  private:
	int _rawBits;
	static const int _fractionalBits = 8;

  public:
	Fixed();
	Fixed(const int intNb);
	Fixed(const float floatNb);
	Fixed(const Fixed& cpy);
	Fixed &operator=(const Fixed& cpy);
	~Fixed();
	bool operator>(const Fixed& cpy) const;
	bool operator<(const Fixed& cpy) const;
	bool operator>=(const Fixed& cpy) const;
	bool operator<=(const Fixed& cpy) const;
	bool operator==(const Fixed& cpy) const;
	bool operator!=(const Fixed& cpy) const;
	static Fixed& min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed& max(Fixed& fixed1, Fixed& raw2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
	Fixed operator+(const Fixed& fixed) const;
	Fixed operator-(const Fixed& fixed) const;
	Fixed operator*(const Fixed& fixed) const;
	Fixed operator/(const Fixed& fixed) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream &operator<<(std::ostream& flux, const Fixed &myObject);

#endif