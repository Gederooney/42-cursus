/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 08:47:02 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/20 20:02:39 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_eat(t_thread *t)
{
	size_t	now;

	now = 0;
	if (t->p->lm + t->t + t->p->g->ttd < now)
	{
		*t->gs = dead;
		t->p->l = dead;
		return (false);
	}
	if (t->p->st == hasthought){
		pthread_mutex_lock(&t->fs[t->p->id]);
		if (t->p->id + 1 == t->p->g->nbrp)
			pthread_mutex_lock(&t->fs[0]);
		else
			pthread_mutex_lock(&t->fs[t->p->id + 1]);
		now = ft_get_time();
		printf("%d %d has taken fork \n", (int)(now - t->t), (int)t->p->id + 1);
		printf("%d %d has taken fork \n", (int)(now - t->t), (int)t->p->id + 1);
		printf("%d %d is eating \n", (int)(now - t->t), (int)t->p->id + 1);
		t->p->lm = now - t->t;
		while (ft_get_time() - now < t->p->g->tte)
		{
			// if (ft_get_time() - t->t > (t->p->lm + t->p->g->ttd))
			// {
			// 	t->p->l = dead;
			// 	*t->gs = dead;
			// 	return (false);
			// }
			usleep(t->p->g->tte / 10);
		}
		t->p->nom++;
		if (t->p->id + 1 == t->p->g->nbrp)
			pthread_mutex_unlock(&t->fs[0]);
		else
			pthread_mutex_unlock(&t->fs[t->p->id + 1]);
		pthread_mutex_unlock(&t->fs[t->p->id]);
		t->p->st = haseateen;
		return (true);
	}
	return (false);
}

bool	ft_sleep(t_thread *t)
{
	size_t	now;

	now = ft_get_time();
	if (*t->gs == alive)
		printf("%d %d is sleeping \n", 
			(int)(now - t->t), (int)(t->p->id + 1));
	while (ft_get_time() - now < t->p->g->tts)
	{
		if (ft_get_time() - t->t > (t->p->lm + t->p->g->ttd)){
			printf("%d %d is dead \n", (int)(ft_get_time() - t->t), 
				(int)(t->p->id + 1));
			t->p->l = dead;
			*t->gs = dead;
			return (false);
		}
		usleep(t->p->g->tts / 10);
	}
	t->p->st = hasslept;
	return (true);
}

bool	ft_think(t_thread *t)
{
	size_t	now;

	now = ft_get_time();
	printf("%d %d is thinking \n", (int)(now - t->t), (int)(t->p->id + 1));
	t->p->st = hasthought;
	return (true);
}

void	*ft_new_routine(void *arg)
{
	t_thread	*t;

	t = (t_thread *)arg;
	while (*t->gs == alive)
	{
		if (*t->gs == dead)
			return ((void *)false);
		if (t->p->st == hasthought && *t->gs == alive && !ft_eat(t))
			return ((void *)false);
		if (*t->gs == dead)
			return ((void *)false);
		if (t->p->st == haseateen && *t->gs == alive && !ft_sleep(t))
			return ((void *)false);
		if (*t->gs == dead)
			return ((void *)false);
		if (t->p->st == hasslept && *t->gs == alive && !ft_think(t))
			return ((void *)false);
		if (*t->gs == dead)
			return ((void *)false);
	}
	return ((void *)true);
}
