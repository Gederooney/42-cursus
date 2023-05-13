/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:33:16 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/08 21:37:11 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> v;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;

	for (int i = 0; i <= 10; i++)
		v.push_back(i);
	try
	{
		std::cout << easyfind(v, 5) << std::endl;
		std::cout << easyfind(v, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return (0);
}
