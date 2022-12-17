/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:49:20 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/17 10:08:03 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

Reader::Reader(std::string& filename, std::string &s1, std::string &s2):  _s1(s1), _s2(s2), _filename(filename)
{
	_fileContent = "";
	_error.state = false;
	_error.type = "No Error"; 
	_error.msg = "No Error";
	std::cout << "Reader constructor called" << std::endl;
}

Reader::~Reader()
{
	std::cout << "Destructor called on reader" << std::endl;
}

int	Reader::run(void)
{
	if(!_error.state)
		this->readFile();
	if (!_error.state)
		this->replaceAllOccurenceOfS1byS2();
	if (!_error.state)
		this->writeFile();
	if (_error.state)
		return 1;
	return 0;
}

void	Reader::readFile(void)
{
	std::ifstream	file(_filename);
	_error.state = false;
	if (file.is_open())
	{
		std::ostringstream ss;
		ss << file.rdbuf();
		_fileContent = ss.str();
		file.close();
	}
	else {
		_error.type = "File";
		_error.msg = "Cannot open file. Please enter a valid filename";
		_error.state = true;
	}
}

void	Reader::replaceAllOccurenceOfS1byS2(void)
{
	size_t	pos;

	pos = 0;
	while (1)
	{
		pos = _fileContent.find(_s1);
		if (pos == std::string::npos)
		{
			std::cout << "stoped" << std::endl;
			break;
		}
		else
		{
			_fileContent.erase(pos, _s1.size());
			_fileContent.insert(pos, _s2);
		}
	}
}

void	Reader::writeFile(void)
{
	std::ofstream file(_filename +".replace", std::ios::out);
	_error.state = false;
	if (file.is_open())
	{
		file << _fileContent;
		file.close();
	}
	else
	{
		_error.state = true;
		_error.type = "File";
		_error.msg = "Cannot create a new file";
	}
}

void	Reader::displayError(void)
{
	std::cout << "Error " << "[Type: " << _error.type << "]; [Message:  " << _error.msg +"];" << std::endl;
}
