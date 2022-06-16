/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:29:28 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/15 21:50:10 by ryebadok         ###   ########.fr       */
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
	pthread_mutex_lock(&t->printer);
	if (t->p->st == eating){
		printf("%d philo %d has taken a fork \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
		printf("%d philo %d has taken a fork \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
		printf("%d philo %d is eating \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
	}
	else if (t->p->st == sleeping)
		printf("%d philo %d is sleeping \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
	else if (t->p->st == thinking)
		printf("%d philo %d is thinking \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
	pthread_mutex_unlock(&t->printer);
}
