/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:46:23 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/17 14:22:02 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int n, char **v)
{
	if (n != 2)
		return (1);
	
	Harl instance;
	void (Harl::*complain)(std::string level);
	complain = &Harl::complain;
	
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int i = 0;
	while (i < 4 && levels[i] != v[1])
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[ " << levels[0] << " ]" << std::endl;
			(instance.*complain)(levels[0]);
		case 1:
			std::cout << "[ " << levels[1] << " ]" << std::endl;
			(instance.*complain)(levels[1]);
		case 2:
			std::cout << "[ " << levels[2] << " ]" << std::endl;
			(instance.*complain)(levels[2]);
		case 3:
			std::cout << "[ " << levels[3] << " ]" << std::endl;
			(instance.*complain)(levels[3]);
			break;
		default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
