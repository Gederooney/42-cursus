/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:08:29 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/24 09:35:44 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0 && nb / 10 == 0)
		ft_putchar('-');
	if (nb / 10 != 0)
		ft_putnbr (nb / 10);
	if (nb < 0)
		ft_putchar((-1 * (nb % 10)) + '0');
	else
		ft_putchar((nb % 10) + '0');
}
