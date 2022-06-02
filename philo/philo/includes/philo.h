/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:55:53 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/01 20:02:45 by ryebadok         ###   ########.fr       */
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


typedef struct s_f
{
	bool			s;
	pthread_mutex_t	*m;
}	t_f;

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
*/
typedef	struct s_p{
	t_arg			*g;
	size_t			id;
	size_t			nom;
	pthread_t		t_id;
	pthread_mutex_t	*s;
}	t_p;

/*
	t: table of philos
	fs: all forks on the table
	g: arguments
	s:	state
*/
typedef	struct s_app
{
	t_p				*t;
	t_f				*fs;
	t_arg			*g;
	pthread_mutex_t	*s;
}	t_app;

bool	ft_init(t_app *app, t_arg *g);
int		ft_error(const char *e_msg);
int		ft_parse(int n, char **v, t_arg *args);

#endif
