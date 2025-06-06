/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:48:08 by bertille          #+#    #+#             */
/*   Updated: 2025/05/01 23:03:24 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <stdexcept>
# include <sstream>
# include <cstdlib>

class BitcoinExchange
{
  private:
	std::map <std::string, double> _data;
  public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& cpy);
	BitcoinExchange& operator=(const BitcoinExchange& cpy);
	~BitcoinExchange();
	void getPrice(std::string input);
};


#endif