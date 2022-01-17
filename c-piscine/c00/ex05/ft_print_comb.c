/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rony Gédéon <ryebadok@student.42quebec.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:18:20 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/12 18:30:46 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_comb(int i, int j)
{
	int	k;

	k = '0';
	while (k <= '9')
	{
		if ((k > i) && (k > j) && (i != '7'))
		{
			write(1, &i, 1);
			write(1, &j, 1);
			write(1, &k, 1);
			write(1, ", ", 2);
		}
		else if ((k > i) && (k > j) && (i == '7'))
		{
			write(1, &i, 1);
			write(1, &j, 1);
			write(1, &k, 1);
		}
		k++;
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;

	i = '0';
	j = '0';
	while (i <= '9')
	{
		while (j <= '9')
		{
			if (j > i)
			{
				write_comb (i, j);
			}
			j++;
		}
		i++;
		j = '0';
	}
}
