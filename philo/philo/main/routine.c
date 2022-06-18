/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/18 10:24:02 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_sleeping(t_thread *t)
{
	size_t	i;

	i = ft_get_time();
	ft_printer(t);
	ft_usleep(t->p->g->tts);
	t->p->st = thinking;
	return (true);
}

bool	ft_thinking(t_thread *t)
{
	size_t	i;

	i = 0;
	ft_printer(t);
	t->p->st = eating;
	return (true);
}

void	*ft_routine(void *args)
{
	t_thread	*t;

	t = (t_thread *)args;
	t->p->lm = ft_get_time() - t->t;
	while (1)
	{
		if ((t->p->g->nbre && t->p->nom == t->p->g->nbre) || *t->gs == dead)
			return (t);
		if (t->p->st == eating)
			ft_eating(t);
		else if (t->p->st == sleeping)
			ft_sleeping(t);
		else if (t->p->st == thinking)
			ft_thinking(t);
	}
	return (NULL);
}

void	*ft_controller(void *arg)
{
	t_app		*table;
	size_t		i;
	size_t		c_time;
	size_t		s_time;
	t_thread	*t;

	table = (t_app *)arg;
	s_time = table->tds[0]->t;
	while (1)
	{
		i = 0;
		c_time = ft_get_time() - s_time;
		while (i < table->g.nbrp)
		{
			if (t->p->nom != t->p->g->nbre)
			{
				t = table->tds[i];
				if(c_time - t->p->lm > t->p->g->ttd)
				{
					table->tds[i]->p->l = dead;
					printf("%d %d is dead\n", (int)c_time, (int)table->tds[i]->p->id + 1);
					*table->gs = dead;
					ft_clean(table);
					return (NULL);
				}
			}
			i++;
		}
	}
	return (NULL);
}
