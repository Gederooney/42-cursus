/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 05:51:27 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/13 15:01:51 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <exception>



class RPN
{
	public:
		RPN(std::string s);
		RPN(const RPN &r);
		~RPN();
		RPN &operator=(const RPN &r);

		void addElement(long n);
		
		void add();
		void sub();
		void mul();
		void div();

		long getResult();

		void execute();

		class EmptyStackException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidExpressionException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		RPN();
		std::string _s;
		std::stack<long> _stack;
};

#endif
