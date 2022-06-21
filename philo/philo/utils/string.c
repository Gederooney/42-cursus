/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:29:28 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/20 23:38:21 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "philo.h"

/*
	Cette fonction prend un pointeur sur chaine de caractères et retourne
	le nombre d'élement sur ce pointeur.
*/
int	ft_charprt_len(char **p)
{
	int	i;

	i = 0;
	while (*p)
	{
		i++;
		p++;
	}
	return (i);
}

void	ft_printer(t_thread *t)
{
	size_t	c_time;

	c_time = ft_get_time();
	// pthread_mutex_lock(t->qc);
	if (*t->gs == alive)
	{
		if (t->p->st == hasthought)
		{
			printf("%d %d is eating \n",
				(int)(c_time - t->t), (int)t->p->id + 1);
		}
		else if (t->p->st == haseateen)
			printf("%d %d is sleeping \n",
				(int)(c_time - t->t), (int)t->p->id + 1);
		else if (t->p->st == hasslept)
		{
			t->p->st = hasthought;
			printf("%d %d is thinking \n",
				(int)(c_time - t->t), (int)t->p->id + 1);
		}
	}
	// pthread_mutex_unlock(t->qc);
}
