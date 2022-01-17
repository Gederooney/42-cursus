/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@42quebec.com>             +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:24:21 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/19 12:39:32 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_checkbase(char *base)
{
	if (ft_strlen(base) == 1 || !*base)
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (0);
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	strlen;
	int	index;

	strlen = ft_strlen(base);
	if (!ft_checkbase(base))
		return ;
	if (nbr < 0 && nbr / strlen == 0)
		write(1, "-", 1);
	if (nbr / ft_strlen(base) != 0)
		ft_putnbr_base (nbr / strlen, base);
	if (nbr % ft_strlen(base) < 0)
	{
		index = (nbr % strlen) * -1;
		ft_putchar(base[index]);
	}
	else
		ft_putchar(base[(nbr % strlen)]);
}
