
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/15 01:05:55 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"



bool	ft_eating_even(t_thread *t){
	if (!(t->p->id % 2)){
		if (!pthread_mutex_lock(&t->fs[t->p->id])){
			printf("philo %d has taken a fork \n", (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id + 1])){
				printf("philo %d has taken a fork \n", (int)t->p->id + 1);
				printf("philo %d is eating \n", (int)t->p->id + 1);
				t->p->s++;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id + 1]);
			}
			pthread_mutex_unlock(&t->fs[t->p->id]);
		}
	}
	else {
		if (!pthread_mutex_lock(&t->fs[t->p->id - 1])){
			printf("philo %d has taken a fork \n", (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id])){
				printf("philo %d has taken a fork \n", (int)t->p->id + 1);
				printf("philo even %d is eating \n", (int)t->p->id + 1);
				t->p->s++;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id]);
			}
			pthread_mutex_unlock(&t->fs[t->p->id - 1]);
		}
	}
	return (true);
}

bool	ft_eating_odd(t_thread *t){
	if (!(t->p->id % 2) && (t->p->id + 1 != t->p->g->nbrp)){
		if (!pthread_mutex_lock(&t->fs[t->p->id])){
			printf("philo %d has taken a fork \n", (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id + 1])){
				printf("philo %d has taken a fork \n", (int)t->p->id + 1);
				printf("philo %d is eating \n", (int)t->p->id + 1);
				t->p->s++;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id + 1]);
			}
			pthread_mutex_unlock(&t->fs[t->p->id]);
		}
	}
	else if (!(t->p->id % 2)){
		if (!pthread_mutex_lock(&t->fs[0])){
			printf("philo %d has taken a fork \n", (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id])){
				printf("philo %d has taken a fork \n", (int)t->p->id + 1);
				printf("philo %d is eating \n", (int)t->p->id + 1);
				t->p->s++;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id]);
			}
			pthread_mutex_unlock(&t->fs[0]);
		}
	}
	else if ((t->p->id % 2)){
		if (!pthread_mutex_lock(&t->fs[t->p->id - 1])){
			printf("philo %d has taken a fork \n", (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id])){
				printf("philo %d has taken a fork \n", (int)t->p->id + 1);
				printf("philo %d is eating \n", (int)t->p->id + 1);
				t->p->s++;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id]);
			}
			pthread_mutex_unlock(&t->fs[t->p->id - 1]);
		}
	}
	return true;
}


bool	ft_eating(t_thread *t){
	pthread_mutex_lock(&t->qc);
	if ((t->p->g->nbrp % 2))
		ft_eating_odd(t);
	else
		ft_eating_even(t);
	
	pthread_mutex_unlock(&t->qc);
	return (true);
}

bool	ft_thinking(t_thread *t){
	printf("philo %d is thinking \n", (int)t->p->id + 1);
	t->p->s++;
	return (true);
}

bool	ft_sleeping(t_thread *t){
	printf("philo %d is sleeping \n", (int)t->p->id + 1);
	t->p->s = 0;
	usleep(1000 * t->p->g->tts);
	return (true);
}

void	*ft_routine(void *args){
	t_thread	*t;

	t = (t_thread *)args;
	while (1){
		if (t->p->s == 0){
			if (!ft_eating(t))
				return (false);
		}
		else if (t->p->s == 2)
			ft_sleeping(t);
		else if (t->p->s == 1)
			ft_thinking(t);
	}
}
