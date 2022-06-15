/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:55:53 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/14 22:36:51 by ryebadok         ###   ########.fr       */
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
	s: state;
	g: args
	nom: number of meal
	lm:	last meal
*/
typedef	struct s_p{
	t_arg			*g;
	size_t			id;
	size_t			nom;
	size_t			lm;
	pthread_t		t_id;
	size_t			s;
}	t_p;

/*
	p -> actual pphilospher
	q -> eating q;
	fs -> all forks
	s -> mutex to lock when modiding sensibles data
	qc -> queu control
*/
typedef	struct s_thread
{
	t_p				*p;
	size_t			*q;
	pthread_mutex_t	*fs;
	pthread_mutex_t	s;
	pthread_mutex_t	qc;
}	t_thread;


/*
	tds: all the threads in this process
*/
typedef	struct s_app
{
	t_thread	**tds;
	t_arg		g;
}	t_app;

void	*ft_routine(void *args);
bool	ft_init(t_app *room, t_arg *g);
int		ft_error(const char *e_msg);
int		ft_parse(int n, char **v, t_arg *args);
bool	ft_makecouverts(t_app *app);

#endif
