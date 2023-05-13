/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:57:31 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 14:43:17 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(): _str(""), _year(0), _month(0), _day(0)
{
}

Date::Date(std::string str): _str(str), _year(0), _month(0), _day(0)
{
	try
	{
		this->parse(str);
		std::vector<std::string> tokens = split(str, '-');
		if (tokens.size() != 3)
			throw InvalidDateException();
		if (tokens[0].length() != 4 || tokens[1].length() != 2 || tokens[2].length() != 2)
			throw InvalidDateException();
		this->_year = std::stoi(tokens[0]);
		this->_month = std::stoi(tokens[1]);
		this->_day = std::stoi(tokens[2]);

		if (!this->isValid())
			throw InvalidDateException();
	}
	catch (std::exception &e)
	{
		throw InvalidDateException();
	}
}

Date::~Date()
{
}

Date::Date(const Date &d)
{
	*this = d;
}

Date &Date::operator=(const Date &d)
{
	if (this != &d)
	{
		this->_str = d._str;
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}
	return (*this);
}

void Date::parse(std::string date)
{
	if (date.length() != 10)
		throw InvalidDateException();
	std::string::iterator it = date.begin();
	while (it != date.end())
	{
		if (!std::isdigit(*it) && *it != '-')
			throw InvalidDateException();
		it++;
	}
}

std::string Date::getStr() const
{
	return (this->_str);
}

bool Date::isValid()
{
	if (_year < 0 || _month < 1 || _month > 12 || _day < 1 || _day > 31)
		return false;
	int maxDays = this->_daysInMonth[_month - 1];
	
	if (_month == 2 && isLeapYear(_year))
		maxDays++;

	if (_day > maxDays)
		return false;
	return (true);
}

bool Date::operator==(const Date &d)
{
	return (this->_year == d._year && this->_month == d._month && this->_day == d._day);
}

bool Date::operator!=(const Date &d)
{
	return (this->_year != d._year || this->_month != d._month || this->_day != d._day);
}

bool Date::operator<(const Date &d)
{
	if (this->_year < d._year)
		return (true);
	else if (this->_year == d._year && this->_month < d._month)
		return (true);
	else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
		return (true);
	return (false);
}

bool Date::operator>(const Date &d)
{
	if (this->_year > d._year)
		return (true);
	else if (this->_year == d._year && this->_month > d._month)
		return (true);
	else if (this->_year == d._year && this->_month == d._month && this->_day > d._day)
		return (true);
	return (false);
}

bool Date::operator<=(const Date &d)
{
	return (*this < d || *this == d);
}

bool Date::operator>=(const Date &d)
{
	return (*this > d || *this == d);
}

bool Date::isInitialized() const
{
	return (this->_year != 0 && this->_month != 0 && this->_day != 0);
}

int Date::daysInMonth()
{
	if (this->_month == 2 && isLeapYear(this->_year))
		return (29);
	return (this->_daysInMonth[this->_month - 1]);
}

int Date::diff(Date &d1, Date &d2)
{
	if (!d1.isInitialized() || !d2.isInitialized())
		throw InvalidDateException();
	if (d1 == d2)
		return (0);
	int diff = 0;

	for (int year = d1._year; year < d2._year; ++year)
		diff += isLeapYear(year) ? 366 : 365;
	
	for (int month = 1; month < d1._month; ++month)
		diff -= d1.daysInMonth();
	
	for (int month = 1; month < d2._month; ++month)
		diff += d2.daysInMonth();
	
	diff += d2._day - d1._day;

	return (diff);
}

const char *Date::InvalidDateException::what() const throw()
{
	return ("Invalid Date");
}

const int Date::_daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
