/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:43:33 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 14:23:27 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::vector<std::string> split(std::string _str, char delim)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(_str);

	while (std::getline(tokenStream, token, delim))
		tokens.push_back(token);
		
	return (tokens);
}

std::string tream(std::string str)
{
	std::string::iterator it = str.begin();
	while (it != str.end() && std::isspace(*it))
		it = str.erase(it);
	if (it != str.end())
	{
		it = str.end() - 1;
		while (it != str.begin() && std::isspace(*it))
			it = str.erase(it);
	}
	return (str);
}

bool isValidDate(std::string date)
{
	const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (date.length() != 10)
		return (false);
	std::string::iterator it = date.begin();
	while (it != date.end())
	{
		if (!std::isdigit(*it) && *it != '-')
			return (false);
		it++;
	}
	std::vector<std::string> tokens = split(date, '-');
	if (tokens.size() != 3)
		return (false);
	if (tokens[0].length() != 4 || tokens[1].length() != 2 || tokens[2].length() != 2)
		return (false);
	try
	{
		int year = std::stoi(tokens[0]);
		int month = std::stoi(tokens[1]);
		int day = std::stoi(tokens[2]);

		if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) 
			return false;

		int maxDay = daysInMonth[month - 1];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			maxDay++;
		
		if (day > maxDay)
			return false;
	}
	catch(const std::exception& e)
	{
		return (false);
	}
	return (true);
}

bool isDouble(std::string str)
{
	std::string::iterator it = str.begin();
	int dot = 0;
	while (it != str.end())
	{
		if (!std::isdigit(*it) && *it != '.')
			return (false);
		if (*it == '.')
			dot++;
		it++;
	}
	if (dot > 1)
		return (false);
	return (true);
}

bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return (true);
	if (year % 400 == 0)
		return (true);
	return (false);
}
