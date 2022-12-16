/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:42:51 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 17:27:47 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_HPP
# define READER_HPP

# include <exception>
# include <iostream>
# include <fstream>
# include <string>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

class Reader
{
	public:
		Reader(int& fd, std::string& s1, std::string& s2);
		~Reader();
	
		int	run(void);
	
	private:
		std::string& _s1;
		std::string& _s2;
		std::string _buffer;
		int&		_fd;
		
		void	readFile(void);
		void	replaceAllOccurenceOfS1byS2(void);
};

# endif
