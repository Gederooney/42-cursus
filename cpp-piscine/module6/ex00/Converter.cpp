/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:39:10 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/10 10:46:14 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(std::string str): Parser(str), _str(str)
{
}

Converter::~Converter()
{
}
bool isInIntRange(double _i)
{
	return (trunc(_i) >= INT_MIN && trunc(_i) <= INT_MAX);
}

std::string Converter::longToChar(long long _i) const
{
	std::stringstream ss;

	if (_i < CHAR_MIN || _i > CHAR_MAX)
		ss << "char: impossible\n";
	else if (!isprint(_i))
		ss << "char: Non displayable\n";
	else
		ss << "char: '" << static_cast<char>(_i) << "'\n";
	return (ss.str());
}

std::string Converter::longToInt(long long _i) const
{
	std::stringstream ss;

	if (_i < INT_MIN || _i > INT_MAX)
		ss << "int: impossible\n";
	else
		ss << "int: " << static_cast<int>(_i) << "\n";
	return (ss.str());
}

std::string Converter::doubleToChar(double _i) const
{
	std::stringstream ss;
	
	if (_i < CHAR_MIN || _i > CHAR_MAX || isnan(_i) || this->getType() == PSEUDO)
		ss << "char: impossible\n";
	else if (!isprint(_i))
		ss << "char: Non displayable\n";
	else
		ss << "char: '" << static_cast<char>(_i) << "'\n";
		return (ss.str());
}

std::string Converter::doubleToFloat(double _i) const
{
	std::stringstream ss;

	if ((_i < -FLT_MAX || _i > FLT_MAX) && this->getType() != PSEUDO)
		ss << "float: impossible\n";
	else
	{
		if (isInIntRange(_i))
			ss << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_i) << "f\n";
		else
			ss << "float: " << static_cast<float>(_i) << "f\n";
	}

	return (ss.str());
}

std::string Converter::doubleToInt(double _i) const
{
	std::stringstream ss;

	if (trunc(_i) < INT_MIN || trunc(_i) > INT_MAX  || isnan(_i))
		ss << "int: impossible\n";
	else
		ss << "int: " << static_cast<int>(_i) << "\n";
	return (ss.str());
}

std::string Converter::fromChar() const
{
	std::stringstream ss;
	char c = _str[0];

	ss <<  "char: '" << c << "'\n";
	ss <<  "int: " << static_cast<int>(c) << "\n";
	ss <<  "float: " << static_cast<float>(c) << ".0f\n";
	ss <<  "double: " << static_cast<double>(c) << ".0\n";
	return (ss.str());
}

std::string Converter::fromInt() const
{
	std::stringstream ss;

	char *endLong = NULL;
	char *endDouble = NULL;

	long long _l = std::strtol(this->_str.c_str(), &endLong, 10);
	double _d = std::strtod(this->_str.c_str(), &endDouble);

	ss << longToChar(_l);
	ss << longToInt(_l);
	ss << doubleToFloat(_d);
	if (isInIntRange(_d))
		ss << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_d) << "\n";
	else
		ss << "double: " << static_cast<double>(_d) << "\n";

	return (ss.str());
}

std::string Converter::fromFloat() const
{
	std::stringstream ss;

	char *endDouble = NULL;
	double _d = std::strtod(this->_str.c_str(), &endDouble);

	ss << doubleToChar(_d);
	ss << doubleToInt(_d);
	ss << doubleToFloat(_d);
	if (isInIntRange(_d))
		ss << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_d) << "\n";
	else
		ss << "double: " << static_cast<double>(_d) << "\n";
	return (ss.str());
}

std::string Converter::fromDouble() const
{
	std::stringstream ss;
	char *endDouble = NULL;
	double _d = std::strtod(this->_str.c_str(), &endDouble);

	ss << doubleToChar(_d);
	ss << doubleToInt(_d);
	ss << doubleToFloat(_d);
	if (isInIntRange(_d))
		ss << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_d) << "\n";
	else
		ss << "double: " << static_cast<double>(_d) << "\n";
	return (ss.str());
}

std::string Converter::fromPseudo() const
{
	std::stringstream ss;
	char *endDouble = NULL;
	double _d = std::strtod(this->_str.c_str(), &endDouble);
	
	ss << doubleToChar(_d);
	ss << doubleToInt(_d);
	ss << doubleToFloat(_d);
	if (this->getType() == INT && isInIntRange(_d))
		ss << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_d) << "\n";
	else
		ss << "double: " << static_cast<double>(_d) << "\n";

	return (ss.str());
}


std::string Converter::convert() const
{
	switch (this->getType())
	{
		case CHAR:
			return (this->fromChar());
		case INT:
			return (this->fromInt());
		case FLOAT:
			return (this->fromFloat());
		case DOUBLE:
			return (this->fromDouble());
		case PSEUDO:
			return (this->fromPseudo());
	}
}

const char *Converter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char *Converter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

std::ostream &operator<<(std::ostream &o, Converter const &src)
{
	o << src.convert();
	return (o);
}
