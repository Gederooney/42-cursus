/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:19:03 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/10 07:28:35 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main (int c, char **v)
{
	if (c != 2)
	{
		 std::cerr << "usage: " << v[0] << " <valeur>" << std::endl;
		 return 1;
	}
	try
	{
		Converter c(v[1]);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
