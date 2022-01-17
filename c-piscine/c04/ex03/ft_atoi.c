/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:32:07 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/23 14:00:06 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		rtn;
	int		sign;

	rtn = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rtn = (rtn * 10) + (*str - '0');
		str++;
	}
	return (rtn * sign);
}
