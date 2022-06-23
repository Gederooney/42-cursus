/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:29:28 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/23 07:57:08 by ryebadok         ###   ########.fr       */
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

bool	ft_print_status(t_thread *t, size_t now)
{
	if (ft_check_death(t) && *t->gs == alive)
	{
		pthread_mutex_lock(t->qc);
		printf("%ld %ld has taken fork \n", now - t->t, t->id + 1);
		printf("%ld %ld has taken fork \n", now - t->t, t->id + 1);
		printf("%ld %ld is eating \n", now - t->t, t->id + 1);
		pthread_mutex_unlock(t->qc);
		return (true);
	}
	return (false);
}
