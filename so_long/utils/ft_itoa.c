/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:08:38 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/08 08:57:38 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_charcount(int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_savenbr(char *dest, int nb, int pos)
{
	pos -= 1;
	if (nb / 10 != 0)
		ft_savenbr(dest, nb / 10, pos);
	if (nb % 10 < 0)
		dest[pos] = (-(nb % 10)) + '0';
	else
		dest[pos] = (nb % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*rtn;

	if (n >= 0)
	{
		rtn = malloc(sizeof(char) * (ft_charcount(n) + 1));
		if (!rtn)
			return (NULL);
		ft_savenbr(rtn, n, ft_charcount(n));
		rtn[ft_charcount(n)] = '\0';
	}
	else
	{
		rtn = malloc(sizeof(char) * (ft_charcount(n) + 2));
		if (!rtn)
			return (NULL);
		rtn[0] = '-';
		ft_savenbr(rtn, n, ft_charcount(n) + 1);
		rtn[ft_charcount(n) + 1] = '\0';
	}
	return (rtn);
}
