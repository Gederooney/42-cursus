/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:18:43 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/10 10:11:28 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <exception>
# include <sstream>
# include <cstdlib>
# include <cfloat>
# include <cmath>

class Parser{
	public:
		enum eType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO
		};
		Parser(std::string str);
		~Parser();

		bool isPseudo();
		void parse();

		bool isValidInput();
		bool isChar( char c );
		int charCount(std::string str, char c);

		eType getType() const;
	private:
		
		eType _type;
		std::string _str;
		
		class BadInputException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class EmptyInputException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
