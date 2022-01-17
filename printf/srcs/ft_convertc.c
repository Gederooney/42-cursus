/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:54:13 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/08 17:41:52 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convertc(const char *s, va_list args)
{
	t_infos	*infos;
	int		count;

	infos = ft_getinfos(s, args);
	if (!infos)
		return (-1);
	count = infos->w;
	if (infos->m && infos->w - 1 > 0)
	{
		ft_putchar(va_arg(args, int));
		while (infos->w-- > 1)
			ft_putchar(' ');
		return (count);
	}
	else if (!infos->m && infos->w - 1 > 0)
	{
		while (infos->w-- > 1)
			ft_putchar(' ');
		ft_putchar(va_arg(args, int));
		return (count);
	}
	else
		ft_putchar(va_arg(args, int));
	free(infos);
	return (1);
}
