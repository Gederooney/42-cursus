/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyFS.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:00:46 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/12 18:09:12 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFS_HPP
# define MYFS_HPP

# include <iostream>
# include <string>
# include <fstream>

using namespace std;

class MyFS
{
	private:
		string _filename;
		string _content;
		string _newContent;
	public:
		MyFS(string filename);
		~MyFS();
		void read();
		void write();
		void append();
		void display();
		void setFilename(string filename);
		string getFilename();
		string getContent();
};

#endif
