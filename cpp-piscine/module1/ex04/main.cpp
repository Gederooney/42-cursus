/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:56:25 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/23 11:09:10 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

int main(int c, char **v)
{
	std::string	s1, s2, filename;

	if(c != 4)
	{
		std::cout << "Error" << std::endl;
		std::cout << "Usage: ./sed [filnename] [string1] [string2]" << std::endl;
		return (-1);
	}
	else
	{
		filename = v[1];
		s1 = v[2];
		s2 = v[3];
		if (s1.empty() || s2.empty())
		{
			std::cout << "Error [type:input] [Message: Strigns cannot not be empty] Usage: ./sed [filnename] [string1] [string2]" << std::endl;
			return (-1);
		}
		Reader fs = Reader(filename, s1, s2);
		if(fs.run())
			fs.displayError();
	}
	return (0);
}
