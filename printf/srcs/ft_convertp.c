/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:59:40 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/07 17:03:09 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convertp(const char *s, va_list args)
{
	//t_infos	*infos;
	unsigned long c;
	char	*t;

	//infos = ft_getinfos(s);
	//if (!infos)
		//return (-1);
	c = va_arg(args, unsigned long);
	t = (char *)s;
	ft_putstr("0x");
	ft_putnbr_base(c, "0123456789abcdef");
	return(1);
}