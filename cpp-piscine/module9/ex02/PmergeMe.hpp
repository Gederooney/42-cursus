/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:33:39 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/13 15:38:46 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <sstream>
# include <string>

template <typename T>
class PmergeMe
{
	public:
		PmergeMe(void){};
		PmergeMe(const PmergeMe &p)
		{
			*this = p;
		}
		~PmergeMe(void){};
		PmergeMe &operator=(const PmergeMe &p)
		{
			(void)p;
			return (*this);
		}
		
		void sort(std::list<T> &l)
		{
			if (l.size() <= 1)
				return ;
			
			std::list<T> l1;
			std::list<T> l2;

			typename std::list<T>::iterator it = l.begin();

			for (unsigned long i = 0; i < l.size() / 2; i++)
			{
				l1.push_back(*it);
				it++;
			}

			for (unsigned long i = l.size() / 2; i < l.size(); i++)
			{
				l2.push_back(*it);
				it++;
			}

			sort(l1);
			sort(l2);

			l = merge(l1, l2);
		}
		void sort(std::deque<T> &d)
		{
			if (d.size() <= 1)
				return ;
			
			std::deque<T> d1;
			std::deque<T> d2;

			typename std::deque<T>::iterator it = d.begin();

			for (unsigned long i = 0; i < d.size() / 2; i++)
			{
				d1.push_back(*it);
				it++;
			}

			for (unsigned long i = d.size() / 2; i < d.size(); i++)
			{
				d2.push_back(*it);
				it++;
			}

			sort(d1);
			sort(d2);

			d = merge(d1, d2);
		}

		std::list<T> merge(std::list<T> &l1, std::list<T> &l2)
		{
			std::list<T> result;

			typename std::list<T>::iterator it1 = l1.begin();
			typename std::list<T>::iterator it2 = l2.begin();

			while (it1 != l1.end() && it2 != l2.end())
			{
				if (*it1 < *it2)
				{
					result.push_back(*it1);
					it1++;
				}
				else
				{
					result.push_back(*it2);
					it2++;
				}
			}
			while (it1 != l1.end())
			{
				result.push_back(*it1);
				it1++;
			}

			while (it2 != l2.end())
			{
				result.push_back(*it2);
				it2++;
			}

			return (result);
		}
		
		std::deque<T> merge(std::deque<T> &d1, std::deque<T> &d2)
		{
			std::deque<T> result;

			typename std::deque<T>::iterator it1 = d1.begin();
			typename std::deque<T>::iterator it2 = d2.begin();

			while (it1 != d1.end() && it2 != d2.end())
			{
				if (*it1 < *it2)
				{
					result.push_back(*it1);
					it1++;
				}
				else
				{
					result.push_back(*it2);
					it2++;
				}
			}

			while (it1 != d1.end())
			{
				result.push_back(*it1);
				it1++;
			}

			while (it2 != d2.end())
			{
				result.push_back(*it2);
				it2++;
			}

			return (result);
		}

		std::string print(std::list<T> &l)
		{
			typename std::list<T>::iterator it = l.begin();
			std::stringstream ss;

			while (it != l.end())
			{
				ss << *it << " ";
				it++;
			}
			return (ss.str());
		}
		std::string print(std::deque<T> &d)
		{
			typename std::deque<T>::iterator it = d.begin();
			std::stringstream ss;

			while (it != d.end())
			{
				ss << *it << " ";
				it++;
			}
			return (ss.str());
		}

		void insert(std::list<T> &l, char **v)
		{
			while (v && *v)
			{
				long val = atol(*v);
				if (val > INT_MAX || val <= 0) throw std::invalid_argument("");
					l.push_back(static_cast<int>(val));
				v++;
			}
		}
		void insert(std::deque<T> &d, char **v)
		{
			while (v && *v)
			{
				long val = atol(*v);
				if (val > INT_MAX || val <= 0)
					throw std::invalid_argument("");
					d.push_back(static_cast<int>(val));
				v++;
			}
		}
};

int isOnlyDigits(char *s);
int parse(char **v);

#endif
template class PmergeMe<int>;

