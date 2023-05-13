/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:23:08 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/11 11:50:21 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){};
		MutantStack(MutantStack const &s): std::stack<T>(s){};
		~MutantStack(){};

		MutantStack &operator=(MutantStack const &s)
		{
			std::stack<T>::operator=(s);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){return (std::stack<T>::c.begin());};
		iterator end(){return (std::stack<T>::c.end());};
};

#endif
