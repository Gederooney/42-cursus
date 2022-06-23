/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:56:41 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/23 07:53:58 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

int	ft_arg_is_int(long x)
{
	return (x >= INT_MIN && x <= INT_MAX);
}

size_t	ft_get_arg(const char *s)
{
	if (ft_only_num(s))
	{
		if (ft_arg_is_int(ft_atol(s)))
			return ((size_t)ft_atoi(s));
	}
	return (0);
}

int	ft_parse(int n, char **v, t_arg *g)
{
	if (n == 5 || n == 6)
	{
		g->nbrp = ft_get_arg(v[0]);
		g->ttd = ft_get_arg(v[1]);
		g->tte = ft_get_arg(v[2]);
		g->tts = ft_get_arg(v[3]);
		if (n == 5)
			return (g->nbrp && g->ttd && g->tte && g->tts);
		if (n == 6)
			g->nbre = ft_get_arg(v[4]);
		return (g->nbrp && g->ttd && g->tte && g->tts && g->nbre);
	}
	return (0);
}
