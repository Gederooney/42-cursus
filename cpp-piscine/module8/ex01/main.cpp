/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:29:38 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/11 11:31:06 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

void callAddNumbers(Span &sp, unsigned int n)
{
	std::vector<int> v;
	unsigned int i = 0;
	for (; i < n - 1; i++)
		v.push_back(i);
	std::vector<int>::iterator it = v.begin();
	
	for(; it != v.end(); it++)
		sp.addNumber(*it);
}

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		Span sp2 = Span(10000);
		callAddNumbers(sp2, 10000);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

		std::cout << sp2[10001] << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
