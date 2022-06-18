/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:02:05 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/18 09:25:46 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_p	*ft_init_single(size_t id, t_arg *g)
{
	t_p		*p;

	p = malloc(sizeof(t_p) * 1);
	p->id = id;
	p->nom = 0;
	p->g = g;
	p->l = alive;
	p->st = eating;
	p->lm = 0;
	return (p);
}

bool	ft_prepare_threads(t_app *table, t_arg *g)
{
	size_t		i;
	t_thread	**tds;

	i = 0;
	tds = malloc(sizeof(t_thread *) * g->nbrp);
	if (!tds)
		return (false);
	while (i < g->nbrp)
	{
		tds[i] = malloc(sizeof(t_thread));
		if (!tds[i])
		{
			while (--i)
			{
				free(tds[i]->p);
				free(tds[i]);
			}
			return (false);
		}
		tds[i]->p = ft_init_single(i, g);
		i++;
	}
	table->tds = tds;
	return (true);
}

bool	ft_prepare_couverts(t_app *table, t_arg *g)
{
	size_t		i;
	pthread_mutex_t	*fs;

	i = 0;
	fs = malloc(sizeof(pthread_mutex_t) * g->nbrp);
	if (!fs)
	{
		// need to destroy threads here;
		return (false);
	}
	while (i < g->nbrp)
	{
		pthread_mutex_init(&fs[i], NULL);
		table->tds[i]->fs = fs;
		i++;
	}
	return (true);
}

bool	ft_prepare_table(t_app *table, t_arg *g)
{
	table->gs = malloc(sizeof(t_life));
	if (!table->gs)
	{
		// you need to destroy threads and mutexs here
		return (false);
	}
	table->g = *g;
	*table->gs = alive;
	return (true);
}

bool	ft_init(t_app *table, t_arg *g)
{
	pthread_mutex_t	*qc;
	size_t			i;

	i = 0;
	qc = malloc(sizeof(pthread_mutex_t));
	if (!qc)
		return (false);
	if (!ft_prepare_threads(table, g))
		return (false);
	if (!ft_prepare_couverts(table, g))
		return (false);
	if (!ft_prepare_table(table, g))
		return (false);
	pthread_mutex_init(qc, NULL);
	while (i < g->nbrp)
	{
		table->tds[i]->qc = qc;
		table->tds[i]->gs = table->gs;
		i++;
	}
	return (true);
}
