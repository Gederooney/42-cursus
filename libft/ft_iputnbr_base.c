/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:24:21 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/21 22:51:26 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nbr_base_len(long long nbr, const char *base, unsigned int *rtn)
{
	int	strlen;

	strlen = ft_strlen(base);
	if (!ft_checkbase(base))
		return ;
	if (nbr < 0 && nbr / strlen == 0)
		*rtn += 1;
	if (nbr / ft_strlen(base) != 0)
		ft_nbr_base_len(nbr /strlen, base, rtn);
	if (nbr % ft_strlen(base) < 0)
		*rtn += 1;
	else
		*rtn += 1;
}

void	ft_iputnbr_base(long long nbr, const char *base)
{
	int	strlen;
	int	index;

	strlen = ft_strlen(base);
	if (!ft_checkbase(base))
		return ;
	if (nbr < 0 && nbr / strlen == 0)
		write(1, "-", 1);
	if (nbr / ft_strlen(base) != 0)
		ft_iputnbr_base(nbr /strlen, base);
	if (nbr % ft_strlen(base) < 0)
	{
		index = (nbr % strlen) * -1;
		ft_putchar(base[index]);
	}
	else
		ft_putchar(base[(nbr % strlen)]);
}
