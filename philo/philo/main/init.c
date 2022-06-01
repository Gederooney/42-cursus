/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:02:05 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/01 14:39:59 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_p	ft_init_single(size_t id, t_arg *g){
	t_p		p;

	p.id = id;
	p.nom = 0;
	p.g = g;
	return (p);
}

bool	ft_init(t_app *app, t_arg *g){
	size_t	i;

	i = 0;
	app->t = malloc(sizeof(t_p) * (int)g->nbrp);
	if (!app->t)
		return (false);
	while (i < g->nbrp){
		app->t[i] = ft_init_single(i,g);
		i++;
	}
	return (true);
}
