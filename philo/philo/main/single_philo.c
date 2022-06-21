/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:19:38 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/21 13:29:23 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	*ft_one_thread(t_thread *t)
{
	size_t now;

	now = ft_get_time();
	pthread_mutex_lock(&t->fs[0]);
	printf("%ld %ld has taken fork \n", now - t->t, t->p->id + 1);
	ft_n_usleep(t, now, t->p->g->ttd);
	pthread_mutex_unlock(&t->fs[0]);
	now = ft_get_time();
	printf("%ld %ld is dead \n", now - t->t, t->p->id + 1);
	return ((void *)true);
}
