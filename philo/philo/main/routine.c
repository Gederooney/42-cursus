/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/14 02:17:13 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_can_i_eat(t_thread *t){
	if(t->p->id % 2){
		if (pthread_mutex_lock(&t->fs[t->p->id]))
			return (false);
	}
	else if((t->p->id + 1) != t->p->g->nbrp){
		if (pthread_mutex_lock(&t->fs[t->p->id - 1]))
			return (false);
	} else if ((t->p->id + 1) != (t->p->g->nbrp)){
		if (pthread_mutex_lock(&t->fs[0]))
			return (false);
	}
	return true;
}

bool	ft_send_to_eat(t_thread *t){
	pthread_mutex_lock(&t->qc);
	if (ft_can_i_eat(t)){
		pthread_mutex_unlock(&t->qc);
		return (true);
	}
	ft_ra(t->q, t->p->g->nbrp);
	pthread_mutex_unlock(&t->qc);
	return false;
}

void	*ft_routine(void *args){
	t_thread	*t;

	t = (t_thread *)args;
	while (1){
		if (t->p->s == 0){
			if (ft_send_to_eat(t)){
				t->p->s = 1;
				printf("philo %d is eating \n", (int)t->p->id);
				usleep(200 * 1000);
				if (t->p->id % 2)
					pthread_mutex_unlock(&t->fs[t->p->id]);
				else if (t->p->id + 1 != t->p->g->nbrp)
					pthread_mutex_unlock(&t->fs[t->p->id - 1]);
				else
					pthread_mutex_unlock(&t->fs[0]);
			}
		}
		else if (t->p->s == 1){
			t->p->s = 2;
			printf("philo %d is sleeping \n", (int)t->p->id);
			usleep(200 * 1000);
		}
		else if (t->p->s == 2){
			t->p->s = 0;
			printf("philo %d is thinking \n", (int)t->p->id);
			usleep(200 * 1000);
		}
	}
	return NULL;
}
