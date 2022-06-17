/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:59:15 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/17 13:52:01 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	ft_feed_not_last(t_thread *t)
{
	size_t	i;

	i = ft_get_time();
	ft_printer(t);
	while ((ft_get_time() - i) < t->p->g->tte)
		usleep(t->p->g->tte / 10);
	t->p->ls = (size_t)(ft_get_time() - t->t);
	t->p->st = sleeping;
	t->p->nom++;
	pthread_mutex_unlock(&t->fs[t->p->id + 1]);
	pthread_mutex_unlock(&t->fs[t->p->id]);
	return (true);
}

bool	ft_feed_last(t_thread *t)
{
	size_t	i;

	i = (size_t)ft_get_time();
	ft_printer(t);
	while ((ft_get_time() - i) < t->p->g->tte)
		usleep(t->p->g->tte / 10);
	t->p->ls = (size_t)(ft_get_time() - t->t);
	t->p->st = sleeping;
	t->p->nom++;
	pthread_mutex_unlock(&t->fs[0]);
	pthread_mutex_unlock(&t->fs[t->p->id]);
	return (true);
}

bool	ft_eating(t_thread *t)
{
	pthread_mutex_lock(t->qc);
	pthread_mutex_lock(&t->fs[t->p->id]);
	printf("%d %d has taken first fork \n",
		(int)(ft_get_time() - t->t), (int)t->p->id + 1);
	if (t->p->id + 1 != t->p->g->nbrp)
	{
		pthread_mutex_lock(&t->fs[t->p->id + 1]);
		printf("%d %d has taken second fork \n",
			(int)(ft_get_time() - t->t), (int)t->p->id + 1);
		pthread_mutex_unlock(t->qc);
		t->p->lm = (size_t)(ft_get_time());
		return (ft_feed_not_last(t));
	}
	else
	{
		pthread_mutex_lock(&t->fs[0]);
		printf("%d %d has taken second fork \n",
			(int)(ft_get_time() - t->t), (int)t->p->id + 1);
		pthread_mutex_unlock(t->qc);
		t->p->lm = (size_t)(ft_get_time());
		return (ft_feed_last(t));
	}
	return (false);
}
