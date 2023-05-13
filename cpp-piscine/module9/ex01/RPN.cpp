/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 05:59:30 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 19:27:05 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _s("")
{
}

RPN::RPN(std::string s) : _s(s)
{
}

RPN::RPN(const RPN &r) : _s(r._s), _stack(r._stack)
{
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &r)
{
	this->_s = r._s;
	this->_stack = r._stack;
	return (*this);
}

void RPN::addElement(int n)
{
	this->_stack.push(n);
}

void RPN::add()
{
	if (this->_stack.size() < 2)
		throw RPN::InvalidExpressionException();
	int b = this->_stack.top();
	this->_stack.pop();
	int a = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(a + b);
}

void RPN::sub()
{
	if (this->_stack.size() < 2)
		throw RPN::InvalidExpressionException();
	int b = this->_stack.top();
	this->_stack.pop();
	int a = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(a - b);
}

void RPN::mul()
{
	if (this->_stack.size() < 2)
		throw RPN::InvalidExpressionException();
	int a = this->_stack.top();
	this->_stack.pop();
	int b = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(a * b);
}

void RPN::div()
{
	if (this->_stack.size() < 2)
		throw RPN::InvalidExpressionException();

	int b = this->_stack.top();
	if (b == 0)
		throw RPN::InvalidExpressionException();
	this->_stack.pop();
	int a = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(a / b);
}

int RPN::getResult()
{
	if (this->_stack.size() != 1)
		throw RPN::InvalidExpressionException();
	return (this->_stack.top());
}

void RPN::execute()
{
	std::string::iterator it = this->_s.begin();
	std::string::iterator ite = this->_s.end();

	while (it != ite)
	{
		char c = *it;
		if (isdigit(c))
			this->_stack.push(c - '0');
		else if (c == '+')
			this->add();
		else if (c == '-')
			this->sub();
		else if (c == '*')
			this->mul();
		else if (c == '/')
			this->div();
		else if (c != ' ')
			throw RPN::InvalidExpressionException();
		it++;
	}
}

const char *RPN::EmptyStackException::what() const throw()
{
	return ("The stack is empty");
}

const char *RPN::NotEnoughElementsException::what() const throw()
{
	return ("Not enough elements in the stack");
}

const char *RPN::InvalidExpressionException::what() const throw()
{
	return ("Error");
}

