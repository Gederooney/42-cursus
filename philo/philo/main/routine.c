/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/12 10:13:56 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

// bool	ft_can_i_eat(t_thread t){
	
// 	return false;
// }

bool	ft_send_to_eat(t_thread t){
	pthread_mutex_lock(&t.qc);
	ft_ra(t.q, t.p.g->nbrp);
	ft_print_arr(t.p.g->nbrp, t.q);
	printf("\n");
	// if (ft_can_i_eat(t)){
	// 	printf("philo %d is eating ", (int)t.p.id);
	// }
	pthread_mutex_unlock(&t.qc);
	return false;
}

void	*ft_routine(void *args){
	t_thread	*t;

	t = (t_thread *)args;
	// if (t->p.id == 0)
	// 	ft_print_arr(t->p.g->nbre, t->q);
	// while (1){
		ft_send_to_eat(*t);
		
	// 	ft_make_sleep();
	// 	ft_make_think();
	// }
	return NULL;
}
