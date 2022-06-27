/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:55:53 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/27 10:15:57 by ryebadok         ###   ########.fr       */
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
	haseateen,
	hasslept,
	hasthought
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
	fs -> all forks
	qc -> queu control
	t -> start time
	gs -> game state;
	id: philo id
	t_id: thread id;
	st: state
	l: life state
	g: args
	nom: number of meal
	lm:	last meal
*/
typedef struct s_thread
{
	size_t			id;
	size_t			nom;
	size_t			lm;
	size_t			t;
	t_life			l;
	t_state			st;
	t_arg			*g;
	t_life			*gs;
	pthread_mutex_t	*fs;
	pthread_mutex_t	*qc;
	pthread_t		t_id;
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

bool	ft_clean(t_app *t);
void	*ft_routine(void *args);
int		ft_error(const char *e_msg);
bool	ft_makecouverts(t_app *app);
bool	ft_check_death(t_thread *t);
bool	ft_controller(t_app *table);
void	*ft_one_thread(t_thread *t);
bool	ft_init(t_app *room, t_arg *g);
int		ft_parse(int n, char **v, t_arg *args);
bool	ft_check_death(t_thread *t);

#endif
