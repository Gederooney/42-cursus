/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:24:21 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/10 09:31:34 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkbase(const char *base)
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

void	ft_putnbr_base(unsigned long nbr, const char *base)
{
	int	strlen;
	int	index;

	strlen = ft_strlen(base);
	if (!ft_checkbase(base))
		return ;
	if (nbr < 0 && nbr / strlen == 0)
		write(1, "-", 1);
	if (nbr / ft_strlen(base) != 0)
		ft_putnbr_base(nbr / strlen, base);
	if (nbr % ft_strlen(base) < 0)
	{
		index = (nbr % strlen) * -1;
		ft_putchar(base[index]);
	}
	else
		ft_putchar(base[(nbr % strlen)]);
}
