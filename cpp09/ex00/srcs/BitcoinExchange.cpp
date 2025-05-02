/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:47:46 by bertille          #+#    #+#             */
/*   Updated: 2025/05/02 16:08:14 by saberton         ###   ########.fr       */
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
		_data = cpy._data;
	return(*this);
}

BitcoinExchange::~BitcoinExchange() {}

static bool checkFormatDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			return (false);
	}
	return (true);
}

static bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0));
}

static bool checkValidDate(std::string date)
{
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1)
		return (false);
	int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return (day <= daysInMonth[month - 1]);
}

static void findValue(double value, std::string date, std::map <std::string, double> _data)
{
	std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
	double res(0.0);
	if (it == _data.end() || it->first != date)
	{
		if (it == _data.begin())
			res = 0.0;
		else
		{
			--it;
			res = it->second;
		}
	}
	else
		res = it->second;
	std::cout << date << " => " << value << " = " << value * res << std::endl;
}

void BitcoinExchange::getPrice(std::string input)
{
	std::ifstream file(input.c_str());
	if (!file)
		throw(std::runtime_error("File data not found"));
	std::string line, date, valueStr;
	double value;
	bool found_valid_line = false;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr) && line != "date | value")
		{
			size_t end = date.find_last_not_of(" \t");
			if (end != std::string::npos)
				date = date.substr(0, end + 1);
			else
				date.clear();
			size_t start = valueStr.find_first_not_of(" \t");
			if (start != std::string::npos)
				valueStr = valueStr.substr(start);
			else
				valueStr.clear();
			std::istringstream ss2(valueStr);
			if (!(ss2 >> value))
				std::cerr << "Error: no number for the date." << std::endl;
			else if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (value >= 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else if (checkFormatDate(date) == false)
				std::cerr << "Error: wrong date format Year-Month-Day." << std::endl;
			else if (checkValidDate(date) == false)
				std::cerr << "Error: date isn't valid." << std::endl;
			else
				findValue(value, date, _data);
			found_valid_line = true;
		}
		else if (line != "date | value")
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	if (!found_valid_line)
		throw(std::runtime_error("No valid data found in data file."));
}
