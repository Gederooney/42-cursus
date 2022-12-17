/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:42:51 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/17 10:05:08 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_HPP
# define READER_HPP

# include <stdexcept>
# include <exception>
# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

typedef struct s_error
{
	std::string type;
	std::string msg;
	bool state;
} t_error;


class Reader
{
	public:
		Reader(std::string& filename, std::string& s1, std::string& s2);
		~Reader();
	
		int		run(void);
		void	displayError(void);
	
	private:
		std::string&	_s1;
		std::string&	_s2;
		std::string&	_filename;
		t_error			_error;
		std::string		_fileContent;
		
		void	readFile(void);
		void	writeFile(void);
		void	replaceAllOccurenceOfS1byS2(void);
};

# endif
