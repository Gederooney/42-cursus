/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:02:43 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/08 17:43:52 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

const char 	*ft_getFlags(const char *s, t_infos *infos)
{
	while (ft_isFlag(*s))
	{
		if (*s == '-')
			infos->m += 1;
		else if (*s == '+')
			infos->pl += 1;
		else if (*s == ' ')
			infos->s += 1;
		else if (*s == '0')
			infos->z += 1;
		else if (*s == '#')
			infos->h += 1;
		s++;
	}
	return (s);
}

void	ft_stars(const char *s, t_infos *infos, va_list args)
{
	if ('0' <= *s && *s <= '9')
	{
		infos->w = ft_atoi(s);
		while ('0' <= *s && *s <= '9')
			s++;
	}
	else if(*s == '*')
	{
		infos->w = va_arg(args, int);
		s++;
	}

	if (*s == '.')
		s++;
	if ('0' <= *s && *s <= '9')
	{
		infos->p = ft_atoi(s);
		while ('0' <= *s && *s <= '9')
			s++;
	}
	else if (*s == '*')
	{
		infos->p = va_arg(args, int);
		s++;
	}
}

t_infos	*ft_getinfos(const char *s, va_list args)
{
	t_infos	*infos;

	infos = malloc(sizeof(t_infos) * 1);
	if (!infos)
		return (NULL);
	s += 1;
	if (ft_isFlag(*s))
		s = ft_getFlags(s, infos);
	ft_stars(s, infos, args);
	return (infos);
}
