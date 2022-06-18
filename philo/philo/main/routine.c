/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/06/18 07:02:38 by ryebadok         ###   ########.fr       */
=======
/*   Updated: 2022/06/18 09:59:19 by ryebadok         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_sleeping(t_thread *t)
{
<<<<<<< Updated upstream
	ft_printer(t);
	ft_usleep(t->p->g->tts);
	t->p->lt = ft_get_time() - t->t;
=======
	size_t	i;

	i = ft_get_time();
	ft_printer(t);
	ft_usleep(t->p->g->tts);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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
=======
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
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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
=======
		c_time = ft_get_time() - s_time;
		while (i < table->g.nbrp)
		{
			t = table->tds[i];
			if(c_time - t->p->lm > t->p->g->ttd)
			{
				table->tds[i]->p->l = dead;
				printf("%d %d %d %d is dead\n", (int)c_time, (int)t->p->lm, (int)t->p->g->ttd, (int)table->tds[i]->p->id + 1);
>>>>>>> Stashed changes
				*table->gs = dead;
				ft_clean(table);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
