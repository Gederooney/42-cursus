/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:49:20 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 16:43:48 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

Reader::Reader(int &fd, std::string &s1, std::string &s2): _s1(s1), _s2(s2), _fd(fd)
{
	_buffer = "";
	std::cout << "Reader constructor called" << std::endl;
}

Reader::~Reader()
{
	std::cout << "Destructor called on reader" << std::endl;
}

int	Reader::run(void)
{
	try
	{
		this->readFile();
		this->replaceAllOccurenceOfS1byS2();
		std::cout << _s1 << _s2 << std::endl;
		return 1;
	}
	catch (int i)
	{
		return i;
	}
}

void	Reader::readFile(void)
{
	ssize_t	res;
	char c;

	res = 1;
	while (res)
	{
		res = read(_fd, &c, 1);
		this->_buffer += c;
	}
	std::cout << _buffer << std::endl;
	return ;
}

void	Reader::replaceAllOccurenceOfS1byS2(void)
{
	
}
