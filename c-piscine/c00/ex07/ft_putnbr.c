/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rony Gédéon <ryebadok@student.42quebec.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:13:47 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/13 20:02:56 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char nbr)
{
	write(1, &nbr, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0 && nb / 10 == 0)
	{
		ft_putchar('-');
	}
	if (nb > 9 || nb < -9)
	{
		ft_putnbr(nb / 10);
	}
	if (nb < 0)
	{
		ft_putchar((nb % 10 * -1) + '0');
	}
	else
	{
		ft_putchar((nb % 10 * 1) + '0');
	}
}
