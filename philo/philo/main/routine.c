/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/20 19:08:58 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_sleeping(t_thread *t)
{
	size_t	i;

	i = ft_get_time();
	ft_printer(t);
	// t->p->st = thinking;
	ft_usleep(t->p->g->tts);
	return (true);
}

bool	ft_thinking(t_thread *t)
{
	size_t	i;

	i = 0;
	ft_printer(t);
	return (true);
}

void	*ft_routine(void *args)
{
	t_thread	*t;

	t = (t_thread *)args;
	t->p->lm = ft_get_time() - t->t;
	// while (1)
	// {
	// 	if (t->p->st == eating 
	// 		&& t->p->g->nbre && t->p->nom == t->p->g->nbre)
	// 		return (t);
	// 	else if (t->p->st == eating)
	// 		ft_eating(t);
	// 	else if (t->p->st == sleeping)
	// 		ft_sleeping(t);
	// 	else if (t->p->st == thinking)
	// 		ft_thinking(t);
	// 	if (*t->gs == dead)
	// 		return (t);
	// }
	return (NULL);
}

bool	ft_stop(t_app *table){
	size_t	stop;
	size_t	i;

	stop = 0;
	i = 0;
	while (i < table->g.nbrp)
	{
		// if (i == 1)	
		// 	printf("%d\n", (int)stop);
		if (table->tds[i]->p->nom == table->g.nbre)
			stop++;
		i++;
	}
	if (stop == table->g.nbrp)
		return (true);
	return (false);
}

void	*ft_controller(void *arg)
{
	t_app		*table;
	// size_t		i;
	// size_t		c_time;
	// size_t		s_time;
	// t_thread	*t;

	table = (t_app *)arg;
	// s_time = table->tds[0]->t;
	// while (1)
	// {
	// 	i = 0;
	// 	c_time = ft_get_time() - s_time;
	// 	if (table->g.nbre && ft_stop(table))
	// 		return (NULL);
	// 	while (i < table->g.nbrp)
	// 	{
	// 		t = table->tds[i];
	// 		if((c_time - t->p->lm > (t->p->g->ttd)) && t->p->st != eating)
	// 		{
	// 			table->tds[i]->p->l = dead;
	// 			printf("%d %d is dead\n", (int)(c_time), (int)table->tds[i]->p->id + 1);
	// 			*table->gs = dead;
	// 			ft_clean(table);
	// 			return (NULL);
	// 		}
	// 		usleep(200);
	// 		i++;
	// 	}
	// }
	return (NULL);
}
