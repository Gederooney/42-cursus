/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rony Gédéon <ryebadok@student.42quebec.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:17:55 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/13 16:22:02 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int i, int j)
{
	char	un;
	char	deux;
	char	trois;
	char	quatre;

	un = (i / 10) + '0';
	deux = (i % 10) + '0';
	trois = (j / 10) + '0';
	quatre = (j % 10) + '0';
	write (1, &un, 1);
	write (1, &deux, 1);
	write (1, " ", 1);
	write (1, &trois, 1);
	write (1, &quatre, 1);
	if (i != 98)
		write (1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_write(i, j);
			j++;
		}
		i++;
	}
}
