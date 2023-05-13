/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:45:13 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/13 09:58:33 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool compareDates(Date &d1, Date &d2)
{
	return (d1 < d2);
}

BitcoinExchange::BitcoinExchange(): _inputFilePath(""), _dataBase(), _error()
{
}

BitcoinExchange::BitcoinExchange(std::string file) : _inputFilePath(file), _dataBase(), _error()
{
	_error.file = DATA;
	_error.path = "./data.csv";
	this->extractDataFromFile(',', "./data.csv");
	std::sort(this->_dataBase.dates.begin(), this->_dataBase.dates.end(), compareDates);

	_error.file = INPUT;
	_error.path = this->_inputFilePath;
	this->extractDataFromFile('|', this->_inputFilePath);

	execute();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b): _inputFilePath(b._inputFilePath), _dataBase(b._dataBase), _error(b._error)
{
	*this = b;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b)
{
	this->_inputFilePath = b._inputFilePath;
	this->_error = b._error;
	this->_dataBase = b._dataBase;
	this->_input = b._input;
	return (*this);
}

void BitcoinExchange::checkTokens(std::vector<std::string> tokens, e_file_type type)
{
	if (tokens.empty())
	{
		_error.type = EMPTY_LINE;
		throw ErrorException(_error);
	}

	std::string tmp1 = tream(tokens[0]);
	std::string tmp2 = tream(tokens[1]);

	switch (type)
	{
		case INPUT:
		{
			if (tokens.size() == 1 && tmp1.empty())
			{
				_error.type = EMPTY_LINE;
				throw ErrorException(_error);
			}
			else if (!(tokens.size() <= 2))
			{
				_error.type = INVALID_LINE;
				throw ErrorException(_error);
			}
			break;
		}
		case DATA:
		{
			if (tokens.size() != 2 || tream(tokens[0]).empty() || tream(tokens[1]).empty())
			{
				_error.type = INVALID_LINE;
				throw ErrorException(_error);
			}
			else if (!isValidDate(tokens[0]) || !isDouble(tokens[1]))
			{
				_error.type = INVALID_LINE;
				throw ErrorException(_error);
			}
			break;
		}
	}
}

void BitcoinExchange::extractDataFromFile(char separator, std::string source_file)
{
	std::ifstream _stream(source_file);
	std::string line;
	std::vector<std::string> tokens;

	// bool first = true;

	if (_stream.is_open())
	{
		while (std::getline(_stream, line))
		{
			tokens = split(line, separator);
			try
			{
				checkTokens(tokens, _error.file);
			}
			catch (ErrorException &e)
			{
				continue;
			}
			switch(_error.file)
			{
				case DATA:
				{
					Date date(tream(tokens[0]));
					this->_dataBase.dates.push_back(date);
					this->_dataBase.values[date.getStr()] = std::stod(tream(tokens[1]));
					break;
				}
				case INPUT:
				{
					tokens[0] = tream(tokens[0]);
					this->_input.push_back(tokens);
				}
			}
			checkTokens(tokens, _error.file);
		}
		
		// if ((this->_dataBase.dates.empty() && _error.file == DATA))
		// {
		// 	_error.type = EMPTY_FILE;
		// 	throw ErrorException(_error);
		// }
	}
	else
	{
		_error.type = OPEN_FILE;
		throw ErrorException(_error);
	}
}


void BitcoinExchange::findMinMaxDates(Date val, Date &min, Date &max)
{
	std::vector<Date>::iterator it = this->_dataBase.dates.begin();
	while (it != this->_dataBase.dates.end())
	{
		if (*it < val && (!min.isInitialized() || *it > min))
			min = *it;
		else if (*it > val && (!max.isInitialized() || *it < max))
		{
			max = *it;
			break;
		}
		it++;
	}
}

void BitcoinExchange::findMaxLessThanX(Date x, Date &min)
{
	size_t left = 0;
	size_t right = this->_dataBase.dates.size() - 1;

	while (left <= right)
	{
		size_t mid =  left + (right - left) / 2;
		if (this->_dataBase.dates[mid] < x)
		{
			min = this->_dataBase.dates[mid];
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
}


Date BitcoinExchange::findClosestDate(Date &val, Date &x, Date &y)
{
	if (x.isInitialized() && y.isInitialized())
	{
		int diffX = Date::diff(x, val);
		int diffY = Date::diff(y, val);

		if (diffX < diffY)
			return (x);
		return (y);
	}
	else if (x.isInitialized())
		return (x);
	return (y);
}

void BitcoinExchange::execute()
{
	std::vector<std::vector<std::string> >::iterator it = this->_input.begin();
	_error.file = INPUT;
	_error.path = this->_inputFilePath;
	while (it != this->_input.end())
	{
		_error.type = NONE;
		try
		{
			double valueFromDb = 1;
			Date date((*it)[0]);
			double value = std::stod((*it)[1]);
			std::string dateStr = date.getStr();
			if (value < 0)
				_error.type = NEGATIVE_NUMBER;
			else if (value > 1000)
				_error.type = LARGE_NUMBER;
			
			if (_error.type != NONE)
				throw ErrorException(_error);
			
			try
			{
				valueFromDb = _dataBase.values.at(dateStr);
			}
			catch (const std::out_of_range& e)
			{
				Date min;
				findMaxLessThanX(date, min);
				try
				{
					valueFromDb = _dataBase.values.at(min.getStr());
				}
				catch (const std::out_of_range& e)
				{
					std::cout << "Error: no data found for " << dateStr << std::endl;
				}
			}
			std::stringstream ss;

			ss << dateStr;
			ss << " => ";
			ss << value;
			ss << " = ";
			ss << std::fixed << std::setprecision(2);
			ss << value * valueFromDb << std::endl;

			std::cout << ss.str();
		}
		catch(const std::out_of_range& e)
		{
			std::cerr << "Error: too large a number." << std::endl;
		}
		catch(const ErrorException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: bad input => " << (*it)[0] << std::endl;
		}
		it++;
	}
}

void BitcoinExchange::ErrorException::buildMessage()
{
	switch (_error.type)
	{
		case OPEN_FILE:
			_msg += "Error: Could not open " + _error.path;
			break;
		case INVALID_LINE:
			_msg += "Error: Invalid line in " + _error.path;
			break;
		case EMPTY_FILE:
			_msg = _msg + "Error: Empty file " + _error.path;
			break;
		case BAD_DATE:
			_msg = _msg + "Error: Bad date in " + _error.path;
			break;
		case LARGE_NUMBER:
			_msg = _msg + "Error: too large a number.";
			break;
		case NEGATIVE_NUMBER:
			_msg = _msg + "Error: not a positive number.";
			break;
		case EMPTY_LINE:
			_msg = _msg + "Error: empty line in " + _error.path;
			break;
		case NONE:
			_msg = _msg + "Error: none";
			break;	
	}
}

const char *BitcoinExchange::ErrorException::what() const throw()
{
	return (_msg.c_str());
}
