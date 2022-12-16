/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:45:43 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 08:47:54 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (int c, char **v)
{
	if (c == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		v++;
		while (*v)
		{
			for (size_t i = 0; i < strlen(*v); i++)
				(*v)[i] = std::toupper((*v)[i]);
			std::cout << *v;
			v++;
			if (*v)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
