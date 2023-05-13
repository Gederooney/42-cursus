/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 05:50:51 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 06:32:53 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int c, char **v)
{
	if (c != 2)
	{
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
		return (1);
	}
	try
	{
		RPN r(v[1]);
		r.execute();
		std::cout << r.getResult() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
