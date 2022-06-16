
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
			printf("%dms philo %d has taken a fork \n", (int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id + 1])){
				printf("%dms philo %d has taken a fork \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				printf("%dms philo %d is eating \n", (int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				t->p->st = sleeping;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id + 1]);
			}
			pthread_mutex_unlock(&t->fs[t->p->id]);
		}
	}
	else {
		if (!pthread_mutex_lock(&t->fs[t->p->id - 1])){
			printf("%dms philo %d has taken a fork \n", (int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id])){
				printf("%dms philo %d has taken a fork \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				printf("%dms philo even %d is eating \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				t->p->st = sleeping;
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
			printf("%dms philo %d has taken a fork \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id + 1])){
				printf("%dms philo %d has taken a fork \n", (int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				printf("%dms philo %d is eating \n", (int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				t->p->st = sleeping;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id + 1]);
			}
			pthread_mutex_unlock(&t->fs[t->p->id]);
		}
	}
	else if (!(t->p->id % 2)){
		if (!pthread_mutex_lock(&t->fs[0])){
			printf("%dms philo %d has taken a fork \n", (int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id])){
				printf("%dms philo %d has taken a fork \n", (int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				printf("%dms philo %d is eating \n", (int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				t->p->st = sleeping;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id]);
			}
			pthread_mutex_unlock(&t->fs[0]);
		}
	}
	else if ((t->p->id % 2)){
		if (!pthread_mutex_lock(&t->fs[t->p->id - 1])){
			printf("%dms philo %d has taken a fork \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
			if (!pthread_mutex_lock(&t->fs[t->p->id])){
				printf("%dms philo %d has taken a fork \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				printf("%dms philo %d is eating \n",(int)((ft_get_time() - t->t) / 1000), (int)t->p->id + 1);
				t->p->st = sleeping;
				t->p->nom++;
				usleep(1000 * t->p->g->tte);
				pthread_mutex_unlock(&t->fs[t->p->id]);
			}
			pthread_mutex_unlock(&t->fs[t->p->id - 1]);
		}
	}
	return true;
}

// bool	ft_eating(t_thread *t){
// 	pthread_mutex_lock(&t->qc);
// 	if ((t->p->g->nbrp % 2))
// 		ft_eating_odd(t);
// 	else
// 		ft_eating_even(t);
	
// 	pthread_mutex_unlock(&t->qc);
// 	return (true);
// }

bool	ft_eating(t_thread *t){
	pthread_mutex_lock(&t->qc);
	if (!pthread_mutex_lock(&t->fs[t->p->id])){
		if (t->p->id + 1 != t->p->g->nbrp)
		{
			if (!pthread_mutex_lock(&t->fs[t->p->id + 1]))
			{
				ft_printer(t);
				usleep(1000 * t->p->g->tte);
				t->p->st = sleeping;
				t->p->nom++;
				pthread_mutex_unlock(&t->fs[t->p->id + 1]);
				pthread_mutex_unlock(&t->fs[t->p->id]);
				pthread_mutex_unlock(&t->qc);
				return (true);
			}
		}
		else
		{
			if (!pthread_mutex_lock(&t->fs[0]))
			{
				ft_printer(t);
				usleep(1000 * t->p->g->tte);
				t->p->st = sleeping;
				t->p->nom++;
				pthread_mutex_unlock(&t->fs[0]);
				pthread_mutex_unlock(&t->fs[t->p->id]);
				pthread_mutex_unlock(&t->qc);
				return (true);
			}
		}
		pthread_mutex_unlock(&t->fs[t->p->id]);
		pthread_mutex_unlock(&t->qc);
		return (false);
	}
	pthread_mutex_unlock(&t->qc);
	return false;
}

bool	ft_thinking(t_thread *t){
	size_t	i;

	i = 0; 
	t->p->st = eating;
	ft_printer(t);
	return (true);
}

bool	ft_sleeping(t_thread *t){
	size_t	i;

	i = 0;
	ft_printer(t);
	while (i < (1000 * t->p->g->tts)){
		usleep(10);
		i += 10;
	}
	t->p->st = thinking;
	return (true);
}

void	*ft_routine(void *args){
	t_thread	*t;

	t = (t_thread *)args;
	while (1){
		if (t->p->st == eating){
			if (!ft_eating(t))
				return (false);
		}
		else if (t->p->st == sleeping)
			ft_sleeping(t);
		else if (t->p->st == thinking)
			ft_thinking(t);
	}
}
