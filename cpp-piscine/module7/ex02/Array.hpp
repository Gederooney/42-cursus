/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:53:51 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/10 16:17:41 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array{
	public:
		Array()
		{
			_els = new T[0];
			_size = 0;
		}
		Array(unsigned int n)
		{
			_els = new T[n];
			_size = n;
		}
		Array(Array const &a)
		{
			*this = a;
		}
		~Array()
		{
			delete [] _els;
		}
		Array &operator=(Array const &a)
		{
			if (this != &a)
			{
				_size = a.size();
				_els = new T[_size];
				for (unsigned int i = 0; i < a.size(); i++)
					_els[i] = a[i];
			}
			return (*this);
		}
		T &operator[](unsigned int index) const
		{
			if (index >= size())
				throw OutOfBoundsException();
			return (_els[index]);
		}

		unsigned int size() const
		{
			return (_size);
		}
		
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index out of bounds");
				}
		};
	private:
		T* _els;
		unsigned int _size;

	
};

#endif
