/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:56:25 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 17:32:43 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

int main(int c, char **v)
{
	int				fd;
	std::string	s1, s2;

	if(c != 4)
	{
		std::cout << "Error" << std::endl;
		std::cout << "Usage: ./sed [filnename] [string1] [string2]" << std::endl;
		return (-1);
	}
	else
	{
		std::ifstream stream(v[1]);
		if (fd < 0 || fd > OPEN_MAX)
			std::cout << "Cannot open " << v[1] << ". Please use a valid filename;" <<std::endl;
		else {
			s1 = v[2];
			s2 = v[3];
			Reader fs = Reader(fd, s1, s2);
			fs.run();
		}
	}
	return (0);
}
