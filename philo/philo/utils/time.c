/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:31:55 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/21 15:21:48 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

bool	ft_n_usleep(t_thread *t, size_t now, size_t count)
{
	if (*t->gs == alive)
	{
		while (ft_get_time() - now < count)
		{
			if (ft_get_time() - t->t > (t->p->lm + t->p->g->ttd))
			{
				pthread_mutex_lock(t->qc);
				t->p->l = dead;
				if (*t->gs == alive)
					printf("%d %d is dead \n", (int)(ft_get_time() - t->t), 
						(int)(t->p->id + 1));
				*t->gs = dead;
				pthread_mutex_unlock(t->qc);
				return (false);
			}
			usleep(t->p->g->tte / 10);
		}
		return (true);
	}
	return (false);
}

