/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyFS.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:00:49 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/12 18:06:04 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyFS.hpp"

MyFS::MyFS(string filename)
{
	this->_filename = filename;
}

MyFS::~MyFS()
{
}

void MyFS::read()
{
	ifstream file(this->_filename);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			this->_content += line;
			this->_content += "\n";
		}
		file.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}