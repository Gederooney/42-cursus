/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:41:29 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/10 09:39:56 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include "Parser.hpp"
# include <cmath>

class Converter: public Parser
{
	public:
		Converter(std::string str);
		~Converter();
		Converter(const Converter &c);
		Converter &operator=(const Converter &c);

		std::string convert() const;

		void getInitialValue();

		class ImpossibleException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NonDisplayableException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
	private:
		std::string _str;

		std::string doubleToChar(double _i) const;
		std::string doubleToFloat(double _i) const;
		std::string doubleToInt(double _i) const;

		std::string longToChar(long long _i) const;
		std::string longToInt(long long _i) const;

		std::string fromChar() const;
		std::string fromInt() const;
		std::string fromFloat() const;
		std::string fromDouble() const;
		std::string fromPseudo() const;

};

std::ostream &operator<<(std::ostream &o, Converter const &src);

#endif
