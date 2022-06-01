/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:00:37 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/01 12:39:28 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	ft_only_num(const char *s){
	while (*s){
		if (*s < '0' || *s > '9')
			return false;
		s++;
	}
	return true;
}

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f' \
			|| c == ' ');
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rtn;

	i = 0;
	sign = 1;
	rtn = 0;
	if (!*str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
		rtn = (rtn * 10) + (str[i++] - '0');
	return (rtn * sign);
}
