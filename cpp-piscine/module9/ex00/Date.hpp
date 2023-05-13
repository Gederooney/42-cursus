/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:55:54 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 14:51:50 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <exception>
# include "utils.hpp"

class Date {
	public:
		Date();
		Date(std::string str);
		~Date();
		Date(const Date &d);

		Date &operator=(const Date &d);

		bool operator==(const Date &d);
		bool operator!=(const Date &d);
		bool operator<(const Date &d);
		bool operator>(const Date &d);
		bool operator<=(const Date &d);
		bool operator>=(const Date &d);

		int daysInMonth();
		static int diff(Date &d1, Date &d2);

		void parse(std::string date);
		std::string getStr() const;
		bool isInitialized() const;

	private:
		std::string _str;

		int _year;
		int _month;
		int _day;

		static const int _daysInMonth[];
		bool isValid();

		class InvalidDateException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
