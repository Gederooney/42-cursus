/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:47:04 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 18:24:59 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\v' || c == '\n'
		|| c == '\r' || c == '\f' || c == ' ');
}

long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	rtn;

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
