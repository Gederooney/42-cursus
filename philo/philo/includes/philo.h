/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:55:53 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/17 16:21:58 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>

typedef enum e_state
{
	eating,
	sleeping,
	thinking
}	t_state;

typedef enum e_life
{
	alive,
	dead
}	t_life;

/*
	nbrp: number of philosophers
	ttd:  time to die
	tte:  time to eat
	tts:  time to sleep
	nbre: number of time a philo must eat
*/
typedef struct s_arg
{
	size_t	nbrp;
	size_t	ttd;
	size_t	tte;
	size_t	tts;
	size_t	nbre;
}	t_arg;

/*
	id: philo id
	t_id: thread id;
	o_f: own fork
	s_f: sibbling fork
	st: state
	l: life
	g: args
	nom: number of meal
	lm:	last meal
	ls:	last sleep
	lt	last think
*/
typedef struct s_p
{
	t_arg		*g;
	size_t		id;
	size_t		nom;
	size_t		lm;
	size_t		ls;
	size_t		lt;
	pthread_t	t_id;
	t_life		l;
	t_state		st;
}	t_p;

/*
	p -> actual pphilospher
	q -> eating q;
	fs -> all forks
	s -> mutex to lock when modiding sensibles data
	qc -> queu control
	t -> start time
	gs -> game state;
*/
typedef struct s_thread
{
	t_p				*p;
	pthread_mutex_t	*fs;
	pthread_mutex_t	s;
	pthread_mutex_t	*qc;
	t_life			*gs;
	long long		t;
}	t_thread;

/*
	tds: all the threads in this process
	gs: game state
*/
typedef struct s_app
{
	t_thread	**tds;
	t_arg		g;
	t_life		*gs;
}	t_app;

void	*ft_servor_routine(void *t);
void	*ft_routine(void *args);
bool	ft_init(t_app *room, t_arg *g);
int		ft_error(const char *e_msg);
int		ft_parse(int n, char **v, t_arg *args);
bool	ft_makecouverts(t_app *app);

#endif
