/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertille <bertille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:47:46 by bertille          #+#    #+#             */
/*   Updated: 2025/04/30 18:57:40 by bertille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream data("data.csv");
	if (!data)
		throw(std::runtime_error("Data file not found"));
	std::string line, date;
	double value;
	bool found_valid_line = false;
	while (std::getline(data, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && ss >> value)
		{
			_data[date] = value; 
			// std::cout << date << " | " << _data[date] << std::endl;
			found_valid_line = true;
		}
	}
	if (!found_valid_line)
		throw(std::runtime_error("No valid data found in data file."));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) { *this = cpy; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& cpy)
{
	if (this != &cpy)
	{
		_data = cpy._data;
	}
	return(*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::getPrice(std::string input)
{
	std::ifstream file(input.c_str());
	if (!file)
		throw(std::runtime_error("File data not found"));
	std::string line, date;
	double value;
	bool found_valid_line = false;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, '|') && ss >> value)
		{
			_data[date] = value;
			// std::cout << date << " | " << _data[date] << std::endl;
			found_valid_line = true;
		}
	}
	if (!found_valid_line)
		throw(std::runtime_error("No valid data found in data file."));
}