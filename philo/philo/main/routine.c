/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/12 10:43:32 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_can_i_eat(t_thread t){
	if (pthread_mutex_lock(&t.fs[t.p.id]))
		return (false);
	// if (pthread_mutex_lock(&t.fs[((t.p.id) + 1) % t.p.g->nbrp]))
	// {
	// 	pthread_mutex_unlock(&t.fs[t.p.id]);
	// 	return (false);
	// }
	printf("philo n* %d is able to eat... ", (int)t.q[0]);
	return true;
}

bool	ft_send_to_eat(t_thread t){
	pthread_mutex_lock(&t.qc);
	if (ft_can_i_eat(t)){
		printf("philo %d is eating \n", (int)t.q[0]);
	}
	ft_ra(t.q, t.p.g->nbrp);
	pthread_mutex_unlock(&t.qc);
	pthread_mutex_unlock(&t.fs[t.p.id]);
	return true;
}

void	*ft_routine(void *args){
	t_thread	*t;

	t = (t_thread *)args;
	// if (t->p.id == 0)
	// 	ft_print_arr(t->p.g->nbre, t->q);
	while (1){
		ft_send_to_eat(*t);
		
	// 	ft_make_sleep();
	// 	ft_make_think();
	}
	return NULL;
}
