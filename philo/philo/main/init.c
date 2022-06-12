/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:02:05 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/12 10:21:21 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_p	ft_init_single(size_t id, t_arg *g){
	t_p		p;

	p.id = id;
	p.nom = 0;
	p.g = g;
	p.s = 0;
	return (p);
}

bool	ft_init(t_app *room, t_arg *g){
	size_t		i;
	pthread_mutex_t	fs[g->nbrp];
	pthread_mutex_t	qc;
	size_t			*queu;

	i = 0;
	room->tds = malloc(sizeof(t_thread) * g->nbrp);
	queu = malloc(sizeof(size_t) * room->g.nbrp);
	room->g = *g;
	if (pthread_mutex_init(&qc, NULL))
		printf("the error is here \n");
	if (room){
		while (i < g->nbrp){
			room->tds[i].p = ft_init_single(i, g);
			if (pthread_mutex_init(&fs[i], NULL))
				printf("this is the fucking error");
			queu[i] = i;
			room->tds[i].fs = fs;
			room->tds[i].qc = qc;
			room->tds[i].q = queu;
			i++;
		}
	}
	return (true);
}
 