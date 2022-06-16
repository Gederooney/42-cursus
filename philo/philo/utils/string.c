/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:29:28 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/16 04:53:28 by ryebadok         ###   ########.fr       */
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

void	ft_printer(t_thread *t){
	if (!pthread_mutex_lock(t->printer))
	{	
		if (t->p->st == eating){
			printf("%d philo %d has taken a fork \n",
				(int)(t->p->lm), (int)t->p->id + 1);
			printf("%d philo %d has taken a fork \n",
				(int)(t->p->lm), (int)t->p->id + 1);
			printf("%d philo %d is eating \n",
				(int)(t->p->lm), (int)t->p->id + 1);
		}
		else if (t->p->st == sleeping)
			printf("%d philo %d is sleeping \n",
				(int)(t->p->ls), (int)t->p->id + 1);
		else if (t->p->st == thinking)
			printf("%d philo %d is thinking \n",
				(int)(t->p->lt), (int)t->p->id + 1);
		pthread_mutex_unlock(t->printer);
	}
}
