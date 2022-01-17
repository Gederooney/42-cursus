/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:59:40 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/08 17:41:31 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convertd(const char *s, va_list args)
{
	t_infos	*infos;
	int		nbr;
	int		count;

	infos = ft_getinfos(s, args);
	count = 0;
	if (!infos)
		return (-1);
	nbr = va_arg(args, int);
	if (!infos->m && infos->w > infos->p)
	{
		if (infos->p > ft_getnbrcount(nbr))
			count = ft_writeloop(infos->w - infos->p, ' ');
		else if (infos->z && !ft_strchr(s, '.'))
			count = ft_writeloop(infos->w - ft_getnbrcount(nbr), '0');
		else
			count = ft_writeloop(infos->w - ft_getnbrcount(nbr), ' ');
	}
	if (infos->p >= ft_getnbrcount(nbr))
		count += ft_writeloop(infos->p - ft_getnbrcount(nbr), '0');
	ft_putnbr(nbr);
	if (infos->m && infos->w > infos->p)
	{
		if (infos->p > ft_getnbrcount(nbr))
			count += ft_writeloop(infos->w - infos->p, ' ');
		else
			count += ft_writeloop(infos->w - ft_getnbrcount(nbr), ' ');
	}
	return (ft_getnbrcount(nbr) + count);
}
