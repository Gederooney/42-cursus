/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:29:28 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/17 14:59:14 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "philo.h"

/*
	Cette fonction prend un pointeur sur chaine de caractères et retourne
	le nombre d'élement sur ce pointeur.
*/
int	ft_charprt_len(char **p)
{
	int	i;

	i = 0;
	while (*p)
	{
		i++;
		p++;
	}
	return (i);
}

void	ft_printer(t_thread *t)
{
	if (t->p->st == eating && t->p->l == alive)
	{
		printf("%d %d is eating \n",
			(int)(t->p->lm - t->t), (int)t->p->id + 1);
	}
	else if (t->p->st == sleeping && t->p->l == alive)
		printf("%d %d is sleeping \n",
			(int)(t->p->ls), (int)t->p->id + 1);
	else if (t->p->st == thinking && t->p->l == alive)
		printf("%d %d is thinking \n",
			(int)(t->p->lt), (int)t->p->id + 1);
}
