/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/18 07:02:38 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_sleeping(t_thread *t)
{
	ft_printer(t);
	ft_usleep(t->p->g->tts);
	t->p->lt = ft_get_time() - t->t;
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
	t->p->lm = ft_get_time();
	while (1)
	{
		if (t->p->g->nbre && t->p->nom == t->p->g->nbre)
			return (t);
		else if (t->p->st == eating)
		{
			if (!ft_eating(t))
				return (false);
		}
		else if ( t->p->st == sleeping)
			ft_sleeping(t);
		else if ( t->p->st == thinking)
			ft_thinking(t);
	}
	return (NULL);
}

void	*ft_controller(void * t)
{
	t_app	*table;
	size_t	i;
	size_t	c_time;
	size_t	s_time;

	table = (t_app *)t;
	while (1)
	{
		i = 0;
		c_time = ft_get_time();
		s_time = table->tds[i]->t;
		while (i < table->g.nbrp)
		{
			if(!table->tds[i]->p->lm 
				&& (c_time > (table->tds[i]->p->g->ttd + s_time)))
			{
				table->tds[i]->p->l = dead;
				printf("%d %d is dead \n", (int)(c_time - s_time), (int)table->tds[i]->p->id + 1);
				*table->gs = dead;
				ft_clean(table);
				return (NULL);
			}
			else if (c_time > (table->tds[i]->p->lm + table->tds[i]->p->g->ttd)
				&& table->tds[i]->p->lm)
			{
				table->tds[i]->p->l = dead;
				printf("%d %d is dead \n", (int)(c_time - s_time), (int)table->tds[i]->p->id + 1);
				*table->gs = dead;
				ft_clean(table);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
