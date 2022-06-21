/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:59:15 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/20 18:37:52 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	ft_feed_not_last(t_thread *t)
{
	ft_printer(t);
	t->p->lm = ft_get_time() - t->t;
	// t->p->st = sleeping;
	ft_usleep(t->p->g->tte);
	t->p->nom++;
	pthread_mutex_unlock(&t->fs[t->p->id + 1]);
	pthread_mutex_unlock(&t->fs[t->p->id]);
	return (true);
}

bool	ft_feed_last(t_thread *t)
{
	ft_printer(t);
	t->p->lm = ft_get_time() - t->t;
	// t->p->st = sleeping;
	ft_usleep(t->p->g->tte);
	t->p->nom++;
	pthread_mutex_unlock(&t->fs[0]);
	pthread_mutex_unlock(&t->fs[t->p->id]);
	return (true);
}

bool	ft_eating(t_thread *t)
{
	pthread_mutex_lock(&t->fs[t->p->id]);
	if (t->p->id + 1 != t->p->g->nbrp)
	{
		pthread_mutex_lock(&t->fs[t->p->id + 1]);
		if (*t->gs == alive){
			printf("%d %d has taken first fork \n",
			(int)(ft_get_time() - t->t), (int)t->p->id + 1);
			printf("%d %d has taken second fork \n",
				(int)(ft_get_time() - t->t), (int)t->p->id + 1);
			return (ft_feed_not_last(t));
		}
	}
	else
	{
		pthread_mutex_lock(&t->fs[0]);
		if (*t->gs == alive)
		{
			printf("%d %d has taken first fork \n",
				(int)(ft_get_time() - t->t), (int)t->p->id + 1);
			printf("%d %d has taken second fork \n",
				(int)(ft_get_time() - t->t), (int)t->p->id + 1);
			return (ft_feed_last(t));
		}
	}
	return (false);
}

void	ft_clean(t_app *t)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = t->g.nbrp;
	free(t->tds[0]->fs);
	free(t->tds[0]->gs);
	while (i < c)
	{
		free(t->tds[i]->p);
		free(t->tds[i]);
		i++;
	}
	exit(0);
}
