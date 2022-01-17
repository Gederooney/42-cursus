/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:17:39 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 12:32:20 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ft_init_fucks(int n)
{
	int				i;
	pthread_mutex_t	*f;

	i = 0;
	f = malloc(sizeof(pthread_mutex_t) * n);
	if (!f)
		return (NULL);
	while (i < n)
	{
		pthread_mutex_init(&(f[i++]), NULL);
	}
	return (f);
}

void	ft_join_threads(t_g **g)
{
	int	i;

	i = 0;
	while (i < g[0]->v->n)
		pthread_join(*(g[i++]->p->t), NULL);
}

t_g	**ft_initthreads(t_var *v)
{
	t_g				**g;
	int				i;
	pthread_mutex_t	*f;

	i = 0;
	g = malloc(sizeof(t_g *) * v->n);
	f = ft_init_fucks(v->n);
	if (!g || !f)
		return (NULL);
	while (i < v->n)
	{
		g[i] = malloc(sizeof(t_g));
		g[i]->p = malloc(sizeof(t_p *));
		g[i]->p->t = malloc(sizeof(pthread_t *));
		g[i]->f = f;
		g[i]->v = v;
		g[i]->p->id = i;
		g[i]->p->s = 0;
		g[i]->p->lm = 0;
		pthread_create(g[i]->p->t, NULL, ft_routine, g[i]);
		i++;
	}
	ft_join_threads(g);
	return (g);
}
