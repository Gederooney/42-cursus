/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:19:38 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/27 10:06:42 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	*ft_one_thread(t_thread *t)
{
	size_t	now;

	now = ft_get_time();
	pthread_mutex_lock(&t->fs[0]);
	printf("%ld %ld has taken fork \n", now - t->t, t->id + 1);
	ft_n_usleep(t, now, t->g->ttd);
	pthread_mutex_unlock(&t->fs[0]);
	return ((void *)true);
}

bool	ft_make_death(t_thread *t, t_arg *g, size_t now, int *i)
{
	if ((now - (t->lm + t->t)) > g->ttd)
	{
		t->l = dead;
		*t->gs = dead;
		printf("%ld %ld is dead \n", now - t->t, t->id + 1);
		*i = -1;
		return (true);
	}
	return (false);
}

bool	ft_full_of_meal(size_t *nom, t_app *table, int *i)
{
	if (table->g.nbre && *nom == table->g.nbre)
	{
		*i = -1;
		return (true);
	}
	return (false);
}

bool	ft_controller(t_app *table)
{
	int		i;
	size_t	now;
	size_t	nom;

	i = 0;
	now = 0;
	nom = 0;
	while (i != -1)
	{
		i = 0;
		while (i < (int)table->g.nbrp)
		{
			now = ft_get_time();
			if (table->g.nbre && table->tds[i]->nom == table->g.nbre
				&& table->tds[i]->st == hasthought)
				nom++;
			if (ft_full_of_meal(&nom, table, &i))
				break ;
			if (ft_make_death(table->tds[i], &table->g, now, &i))
				break ;
			usleep(25);
			i++;
		}
	}
	return (true);
}

bool	ft_check_death(t_thread *t)
{
	size_t	now;

	now = 0;
	now = ft_get_time();
	if ((t->lm + t->t + t->g->ttd < now))
		return (false);
	return (true);
}
