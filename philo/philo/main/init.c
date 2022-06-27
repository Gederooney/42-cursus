/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:02:05 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/27 08:19:44 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_single(size_t id, t_thread *t)
{
	t->id = id;
	t->nom = 0;
	t->l = alive;
	t->st = hasthought;
	t->lm = 0;
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
				free(tds[i]);
			return (false);
		}
		ft_init_single(i, tds[i]);
		i++;
	}
	table->tds = tds;
	return (true);
}

bool	ft_prepare_couverts(t_app *table, t_arg *g)
{
	size_t			i;
	pthread_mutex_t	*fs;

	i = 0;
	fs = malloc(sizeof(pthread_mutex_t) * g->nbrp);
	if (!fs)
	{
		free(table->tds[0]->qc);
		while (i++ < g->nbrp)
			free(table->tds[i - 1]);
		return (false);
	}
	i = 0;
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
	size_t	i;

	i = 0;
	table->gs = malloc(sizeof(t_life));
	if (!table->gs)
	{
		free(table->tds[0]->qc);
		while (i++ < g->nbrp)
			pthread_mutex_destroy(&table->tds[i - 1]->fs[i - 1]);
		free(table->tds[0]->fs);
		i = 0;
		while (i++ < g->nbrp)
			free(table->tds[i - 1]);
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
	{
		free(qc);
		return (false);
	}
	if (!ft_prepare_couverts(table, g))
		return (false);
	if (!ft_prepare_table(table, g))
		return (false);
	pthread_mutex_init(qc, NULL);
	while (i < g->nbrp)
	{
		table->tds[i]->qc = qc;
		table->tds[i]->gs = table->gs;
		table->tds[i]->g = g;
		i++;
	}
	return (true);
}
