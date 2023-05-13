/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:45:21 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 17:32:01 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <vector>
# include <exception>
# include <map>
# include <algorithm>

# include "utils.hpp"
# include "Date.hpp"

struct Data
{
	std::vector<Date> dates;
	std::map<std::string, double> values;
};

enum e_file_type
{
	INPUT,
	DATA
};

enum e_error
{
	NONE,
	OPEN_FILE,
	INVALID_LINE,
	EMPTY_FILE,
	NEGATIVE_NUMBER,
	LARGE_NUMBER,
	BAD_DATE,
	EMPTY_LINE
};

struct s_error
{
	e_error type;
	e_file_type file;
	std::string path;
};

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string file);
		BitcoinExchange(const BitcoinExchange &b);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &b);


	private:
		std::string _inputFilePath;
		Data _dataBase;
		std::vector<std::vector<std::string> > _input;
		s_error _error;

		BitcoinExchange();
		void checkTokens(std::vector<std::string> tokens, e_file_type type);
		void extractDataFromFile(char separator, std::string source_file);
		void findMinMaxDates(Date val, Date &min, Date &max);
		void findMaxLessThanX(Date x, Date &min);

		Date findClosestDate(Date &val, Date &x, Date &y);

		void execute();

		class ErrorException : public std::exception {
			public:
				ErrorException(s_error err) throw() : _error(err) { buildMessage(); }
				virtual ~ErrorException() throw() {};
				virtual const char* what() const throw();

			private:
				s_error _error;
				std::string _msg;

				void buildMessage();
		};

};

#endif
