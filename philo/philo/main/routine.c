/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:57 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/15 01:02:31 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_can_i_eat(t_thread *t){
	if(!(t->p->id % 2)){
		if (pthread_mutex_lock(&t->fs[t->p->id]))
			return (false);
	}
	else if((t->p->id + 1) != t->p->g->nbrp){
		if (pthread_mutex_lock(&t->fs[t->p->id - 1]))
			return (false);
	} else if (!(t->p->g->nbrp % 2) && 
		(t->p->id + 1) != (t->p->g->nbrp)){
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
	} else {
		// printf("i cannot eat %d \n", (int)t->p->id);
	}
	ft_ra(t->q, t->p->g->nbrp);
	pthread_mutex_unlock(&t->qc);
	return false;
}

void	ft_add_to_queu(t_thread *t){
	pthread_mutex_lock(&t->qc);
		printf("this is it\n");
	pthread_mutex_unlock(&t->qc);
}

// void	*ft_routine(void *args){
// 	t_thread	*t;

// 	t = (t_thread *)args;
// 	while (1){
// 		if (t->p->s == 0){
// 			if (ft_send_to_eat(t)){
// 				t->p->s = 1;
// 				printf("philo %d is eating \n", (int)t->p->id);
// 				usleep(200 * 1000);
// 				if (t->p->id % 2)
// 					pthread_mutex_unlock(&t->fs[t->p->id]);
// 				else if (t->p->id + 1 != t->p->g->nbrp)
// 					pthread_mutex_unlock(&t->fs[t->p->id - 1]);
// 				else
// 					pthread_mutex_unlock(&t->fs[0]);
// 			}
// 		}
// 		else if (t->p->s == 1){
// 			t->p->s = 2;
// 			printf("philo %d is sleeping \n", (int)t->p->id);
// 			usleep(200 * 1000);
// 		}
// 		else if (t->p->s == 2){
// 			t->p->s = 0;
// 			printf("philo %d is thinking \n", (int)t->p->id);
// 			usleep(200 * 1000);
// 			ft_add_to_queu(t);
// 		}
// 	}
// 	return NULL;
// }

bool	ft_eating_even(t_thread *t){
	if (!(t->p->id % 2)){
		if (!pthread_mutex_lock(&t->fs[t->p->id])){
			printf("philo even %d is eating \n", (int)t->p->id);
			t->p->s++;
			usleep(1000 * 600);
			pthread_mutex_unlock(&t->fs[t->p->id]);
		}
	}
	else {
		if (!pthread_mutex_lock(&t->fs[t->p->id - 1])){
			printf("philo even %d is eating \n", (int)t->p->id);
			t->p->s++;
			usleep(1000 * 600);
			pthread_mutex_unlock(&t->fs[t->p->id - 1]);
		}
	}
	return (true);
}

bool	ft_eating_odd(t_thread *t){
	if (!(t->p->id % 2) && (t->p->id + 1 != t->p->g->nbrp)){
		if (!pthread_mutex_lock(&t->fs[t->p->id])){
			printf("philo %d odd not last is eating \n", (int)t->p->id + 1);
			t->p->s++;
			usleep(1000 * 600);
			pthread_mutex_unlock(&t->fs[t->p->id]);
		}
	}
	else if (!(t->p->id % 2)){
		if (!pthread_mutex_lock(&t->fs[0])){
			printf("philo %d odd is eating \n", (int)t->p->id + 1);
			t->p->s++;
			usleep(1000 * 600);
			pthread_mutex_unlock(&t->fs[0]);
		}
	}
	else if ((t->p->id % 2)){
		if (!pthread_mutex_lock(&t->fs[t->p->id - 1])){
			printf("philo %d odd is eating \n", (int)t->p->id + 1);
			t->p->s++;
			usleep(1000 * 600);
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
	usleep(1000 * 600);
	return (true);
}

bool	ft_sleeping(t_thread *t){
	printf("philo %d is sleeping \n", (int)t->p->id + 1);
	t->p->s = 0;
	usleep(1000 * 600);
	return (true);
}

void	*ft_routine(void *args){
	t_thread	*t;

	t = (t_thread *)args;
	while (1){
		if (t->p->s == 0)
			ft_eating(t);
		else if (t->p->s == 1)
			ft_thinking(t);
		else if (t->p->s == 2)
			ft_sleeping(t);
	}
}
