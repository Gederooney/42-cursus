/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:02:05 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/16 03:55:20 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_p	*ft_init_single(size_t id, t_arg *g){
	t_p		*p;

	p = malloc(sizeof(t_p) * 1);
	p->id = id;
	p->nom = 0;
	p->g = g;
	p->l = living;
	p->st = eating;
	p->nom = 0;
	p->lm = 0;
	p->ls = 0;
	p->lt = 0;
	return (p);
}

// void	ft_allocate_memory(t_app *table){}

bool	ft_init(t_app *room, t_arg *g){
	size_t		i;
	pthread_mutex_t	*fs;
	pthread_mutex_t	*qc;
	pthread_mutex_t	*printer;

	i = 0;
	fs = malloc(sizeof(pthread_mutex_t) * g->nbrp);
	room->tds = malloc(sizeof(t_thread *) * g->nbrp);
	printer = malloc(sizeof(pthread_mutex_t *) * 1);
	qc = malloc(sizeof(pthread_mutex_t *) * 1);
	room->g = *g;
	if (pthread_mutex_init(qc, NULL))
		return (false);
	if (pthread_mutex_init(printer, NULL))
		return (false);
	if (room && room->tds ){
		while (i < g->nbrp){
			room->tds[i] =malloc(sizeof(t_thread) * 1);
			room->tds[i]->p = ft_init_single(i, g);
			pthread_mutex_init(&fs[i], NULL);
			room->tds[i]->fs = fs;
			room->tds[i]->qc = qc;
			room->tds[i]->printer = printer;
			i++;
		}
	}
	return (true);
}
 