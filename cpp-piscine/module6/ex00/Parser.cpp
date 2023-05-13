/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:28:05 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/10 15:28:33 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(std::string str){
	this->_str = str;
	parse();
}

Parser::~Parser()
{
}

Parser::eType Parser::getType() const
{
	return (this->_type);
}

bool Parser::isPseudo()
{
	return (_str == "nan" || _str == "nanf" || _str == "+inf" || _str == "+inff" || _str == "-inf" || _str == "-inff");
}

bool Parser::isChar(char c)
{
	return (c >= 32 && c <= 126);
}

int Parser::charCount(std::string str, char c)
{
	int i = 0;
	int count = 0;
	
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

bool Parser::isValidInput()
{
	if (_str.empty())
		throw EmptyInputException();
	if (isPseudo())
		return true;
	if (charCount(_str, '.') > 1 ||
			charCount(_str, 'f') > 1 ||
			charCount(_str, '+') > 1 ||
			charCount(_str, '-') > 1 ||
			charCount(_str, ' ') > 0) 
				return false;
	if (_str.length() > 1)
	{
		int i = 0;

		while (_str[i])
		{
			if (!isdigit(_str[i]) && _str[i] != '.' && _str[i] != 'f' && _str[i] != '+' && _str[i] != '-')
				return false;
			if (_str[i] == '+' || _str[i] == '-')
			{
				if (!isdigit(_str[i + 1]) && _str[i + 1] != '.')
				{
					return false;
				}
				else if (i != 0 && !isdigit(_str[i - 1]))
				{
					return false;
				}
			}
			i++;
		}
	}
	return true;
}

void Parser::parse()
{
	if (!isValidInput())
		throw BadInputException();
	if (isPseudo())
		_type = PSEUDO;
	else if (_str.length() == 1 && !isdigit(_str[0]))
		_type = CHAR;
	else
	{
		if (_str.find('.') == std::string::npos && _str.find('f') == std::string::npos)
				_type = INT;
		else if (_str.find('.') != std::string::npos && _str.find('f') == std::string::npos)
			_type = DOUBLE;
		else if (_str.find('.') != std::string::npos && _str.find('f') != std::string::npos)
			_type = FLOAT;
		else
			throw BadInputException();
	}
}



const char *Parser::BadInputException::what() const throw()
{
	const char *msg = "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible\n";
	return (msg);
}

const char *Parser::EmptyInputException::what() const throw()
{
	return ("Cannot convert empty string.");
}
