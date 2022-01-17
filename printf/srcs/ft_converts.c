/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:59:40 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/08 18:29:06 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_writep(const char *s, int n)
{
	int		i;
	char	c;

	i = -1;
	while (++i < n && *s)
	{
		c = *s++;
		write(1, &c, 1);
	}
	return (n);
}

int	ft_converts(const char *s, va_list args)
{
	char	*temp;
	t_infos	*i;
	int		counts;

	i = ft_getinfos(s, args);
	if (!i)
		return (-1);
	temp = va_arg(args, char *);
	counts = 0;
	if (i->w > ft_strlen(temp))
	{
		if (i->p < ft_strlen(temp))
		{
			if (i->w > i->p || !ft_strchr(s, '.'))
			{
				if (i->m)
					counts += ft_writep(temp, i->p);
				if (i->z)
					counts += ft_writeloop(i->w - i->p, '0');
				else
					counts += ft_writeloop(i->w - i->p, ' ');
				if (!i->m)
					counts += ft_writep(temp, i->p);
			}
			else
			{
				counts += ft_writeloop(i->w - i->p, '0');
				counts += ft_writep(temp, i->p);
			}
		}
		else if (i->p >= ft_strlen(temp))
		{
			if (i->w > i->p || !ft_strchr(s, '.'))
			{
				if (i->m)
					counts += ft_writep(temp, i->p);
				counts += ft_writeloop(i->w - ft_strlen(temp), ' ');
				if (!i->m)
					counts += ft_writep(temp, i->p);
			}
			else
			{
				counts += ft_writeloop(i->w - i->p, '0');
				counts += ft_writep(temp, i->p);
			}
		}
	} else if (i->w <= ft_strlen(temp))
		counts += ft_writep(temp, i->p);
	return (counts);
}