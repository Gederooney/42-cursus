/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:33:47 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 20:55:17 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int isOnlyDigits(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int parse(char **v)
{
	while (v && *v)
	{
		if (!isOnlyDigits(*v))
			throw std::invalid_argument("Error");
		v++;
	}
	return (0);
}
