/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:22:55 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 12:42:03 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_p *p, char *str)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld philo %d is %s\n", tv.tv_sec, p->id + 1, str);
}

void	ft_eating(t_g *g)
{
	if (!(g->p->id % 2) && !pthread_mutex_lock(&g->f[g->p->id])
		&& !pthread_mutex_lock(&g->f[g->p->id + 1]))
	{
		ft_print(g->p, "eating");
		g->p->lm = ft_get_time();
		g->p->s += 1;
	}
	else if (g->p->id % 2 && !pthread_mutex_lock(&g->f[g->p->id])
		&& !pthread_mutex_lock(&g->f[g->p->id - 1]))
	{
		ft_print(g->p, "eating 2");
		g->p->lm = ft_get_time();
		g->p->s += 1;
	}
}

void	ft_sleeping(t_g *g)
{
	if (!(g->p->id % 2))
		pthread_mutex_unlock(&g->f[g->p->id + 1]);
	else
		pthread_mutex_unlock(&g->f[g->p->id - 1]);
	pthread_mutex_unlock(&g->f[g->p->id]);
	ft_print(g->p, "sleeping");
	g->p->s += 1;
}

void	ft_thinking(t_g *g)
{
	ft_print(g->p, "thinking");
	g->p->s += 1;
}

void	*ft_routine(void *arg)
{
	t_g	*g;

	g = (void *)arg;
	while (1)
	{
		if (g->p->s == 0)
			ft_eating(g);
		else if (g->p->s == 1
			&& (ft_get_time() - g->p->lm) >= (g->v->te))
			ft_sleeping(g);
		else if (g->p->s == 2
			&& (ft_get_time() - g->p->lm) >= (g->v->te + g->v->ts))
			ft_thinking(g);
		else if (g->p->s == 3)
			g->p->s = 0;
	}
	return (NULL);
}
