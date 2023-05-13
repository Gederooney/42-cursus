/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:29:52 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/11 11:31:33 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _v()
{
}

Span::Span(unsigned int n) : _n(n), _v()
{
}

Span::Span(const Span &s) : _n(s._n), _v(s._v)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &s)
{
	this->_n = s._n;
	this->_v = s._v;
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_v.size() >= this->_n)
		throw Span::FullException();
	this->_v.push_back(n);
}

int Span::shortestSpan()
{
	if (this->_v.size() <= 1)
		throw Span::NotEnoughException();
	std::list<int> tmp = this->_v;
	// std::sort(tmp.begin(), tmp.end());
	tmp.sort();

	std::list<int>::iterator prev = tmp.begin();
	std::list<int>::iterator curr = prev;

	++curr;
	
	int min = *curr - *prev;
	for (; curr != tmp.end(); curr++)
	{
		if (*curr - *prev < min)
			min = *curr - *prev;
		prev++;
	}
	return (min);
}

int Span::longestSpan()
{
	if (this->_v.size() <= 1)
		throw Span::NotEnoughException();
	std::list<int> tmp = this->_v;
	// std::sort(tmp.begin(), tmp.end());
	tmp.sort();

	std::list<int>::iterator start = tmp.begin();
	std::list<int>::iterator end = tmp.end();
	end--;

	return (*end - *start);
}

const char *Span::FullException::what() const throw()
{
	return ("The container is full");
}

const char *Span::NotEnoughException::what() const throw()
{
	return ("Not enough elements in the container");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Out of range");
}

const char *Span::NoSpanFoundException::what() const throw()
{
	return ("Out of range");
}

int Span::operator[](unsigned int i)
{
	if (i >= this->_v.size())
		throw Span::NoSpanException();
	std::list<int>::iterator it = this->_v.begin();
	for (unsigned int j = 0; j < i; j++)
		it++;

	return (*it);
}

