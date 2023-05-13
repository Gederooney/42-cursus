/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:29:56 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/11 11:01:05 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <exception>
# include <list>

class Span
{
	private:
		unsigned int _n;
		std::list<int> _v;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &s);
		~Span();

		Span &operator=(const Span &s);
		
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		int operator[](unsigned int i);

		class FullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoSpanFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
