/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:55:16 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 11:11:17 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <pthread.h>
# include <sys/time.h>

/*
	Cette structure permet de sauvegarder toutes mes variables
	n = nombres de philosophers
	td = time to die
	te = time to eat
	ts = time to sleep
	nte = number of time a philosopher must eat
*/
typedef struct s_var
{
	int	n;
	int	td;
	int	te;
	int	ts;
	int	nte;
}	t_var;

/*
	Cette structure representera un philosopher à la fois
	s: State
		le state peut prendre quatre variables possible: 0, 1, 2 ou -1
		0 ==> entrain de dormir
		1 ==> entrain de reflechir
		2 ==> entrain de manger
		-1 ==> mort
	lm: last meal
*/

typedef struct s_p
{
	pthread_t	*t;
	int			id;
	int			s;
	long long	lm;
}	t_p;

/*
	f: Fork
		la fourchette peut elle aussi prendre deux valeurs
		0 ==> indisponible
		1 ==> disponible
*/
typedef struct s_g
{
	t_var			*v;
	t_p				*p;
	pthread_mutex_t	*f;
}	t_g;
#endif
