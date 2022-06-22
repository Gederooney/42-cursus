/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 08:47:02 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/22 11:40:06 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_check_death(t_thread *t)
{
	size_t	now;

	now = 0;
	now = ft_get_time();
	if ((t->lm + t->t + t->g->ttd < now))
		return (false);
	return (true);
}

bool	ft_eat(t_thread *t)
{
	size_t	now;

	now = 0;
	if (!ft_check_death(t))
		return (false);
	if (t->st == hasthought){
		pthread_mutex_lock(&t->fs[t->id]);
		if (t->id + 1 == t->g->nbrp)
			pthread_mutex_lock(&t->fs[0]);
		else
			pthread_mutex_lock(&t->fs[t->id + 1]);
		now = ft_get_time();
		ft_print_status(t, now);
		t->lm = now - t->t;
		ft_n_usleep(t, now, t->g->tte);
		t->nom++;
		if (t->id + 1 == t->g->nbrp)
			pthread_mutex_unlock(&t->fs[0]);
		else
			pthread_mutex_unlock(&t->fs[t->id + 1]);
		pthread_mutex_unlock(&t->fs[t->id]);
		t->st = haseateen;
		return (true);
	}
	return (false);
}

bool	ft_sleep(t_thread *t)
{
	size_t	now;

	now = ft_get_time();
	if (ft_check_death(t) && *t->gs == alive)
	{
		pthread_mutex_lock(t->qc);
		printf("%d %d is sleeping \n", 
			(int)(now - t->t), (int)(t->id + 1));
		pthread_mutex_unlock(t->qc);
	}
	ft_n_usleep(t, now, t->g->tts);
	t->st = hasslept;
	return (true);
}

bool	ft_think(t_thread *t)
{
	size_t	now;

	now = ft_get_time();
	if (ft_check_death(t) && *t->gs == alive)
		printf("%d %d is thinking \n",
			(int)(now - t->t), (int)(t->id + 1));
	t->st = hasthought;
	return (true);
}

void	*ft_routine(void *arg)
{
	t_thread	*t;

	t = (t_thread *)arg;
	if (t->g->nbrp == 1)
		return (ft_one_thread(t));
	while (*t->gs == alive)
	{
		if (*t->gs == dead || (t->g->nbre && t->nom == t->g->nbre))
			return ((void *)false);
		if (t->st == hasthought && *t->gs == alive && !ft_eat(t))
			return ((void *)false);
		if (*t->gs == dead)
			return ((void *)false);
		if (t->st == haseateen && *t->gs == alive && !ft_sleep(t))
			return ((void *)false);
		if (*t->gs == dead)
			return ((void *)false);
		if (t->st == hasslept && *t->gs == alive && !ft_think(t))
			return ((void *)false);
		if (*t->gs == dead)
			return ((void *)false);
	}
	return ((void *)true);
}
