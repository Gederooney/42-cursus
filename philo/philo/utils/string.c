/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:29:28 by ryebadok          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/06/17 22:10:43 by ryebadok         ###   ########.fr       */
=======
/*   Updated: 2022/06/18 09:53:37 by ryebadok         ###   ########.fr       */
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
	if (t->p->st == eating && *t->gs != dead)
=======
	size_t	c_time;

	c_time = ft_get_time();
	// pthread_mutex_lock(t->qc);
	if (*t->gs == alive)
>>>>>>> Stashed changes
	{
		if (t->p->st == eating)
			printf("%d %d is eating \n",
				(int)(c_time - t->t), (int)t->p->id + 1);
		else if (t->p->st == sleeping)
			printf("%d %d is sleeping \n",
				(int)(c_time - t->t), (int)t->p->id + 1);
		else if (t->p->st == thinking)
			printf("%d %d is thinking \n",
				(int)(c_time - t->t), (int)t->p->id + 1);
	}
<<<<<<< Updated upstream
	else if (t->p->st == sleeping && *t->gs != dead)
		printf("%d %d is sleeping \n",
			(int)(t->p->ls), (int)t->p->id + 1);
	else if (t->p->st == thinking && *t->gs != dead)
		printf("%d %d is thinking \n",
			(int)(t->p->lt), (int)t->p->id + 1);
=======
	// pthread_mutex_unlock(t->qc);
>>>>>>> Stashed changes
}
