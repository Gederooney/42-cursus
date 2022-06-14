/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:13:46 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/14 01:59:24 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
void ft_help(void){
	printf("\n");
	printf("%s\n", "--help philosophers");
		printf("\n");
	printf("%s\n", "usage: ./philo np td te ts nte");
	printf("\n");
	printf("%s\n", "Vous devez avoir au moins 4 et au plus 5 arguments");
	printf("\n");
	printf("%s\n", "-------  LIST des arguments");
	printf("%s\n", "------- np : le nombre de philo");
	printf("%s\n", "------- td : temps de mourir");
	printf("%s\n", "------- te : temps de manger");
	printf("%s\n", "------- ts : temps de dormir");
	printf("%s\n", "------- ts : max de fois un philo doit manger: optionel");
}

int	ft_error(const char *e_msg){
	printf("%s\n", e_msg);
	ft_help();
	return (1);
}

size_t	*ft_make_queu(t_arg *g){
	size_t	*queu;
	size_t	i;

	queu = malloc(sizeof(size_t) * g->nbrp);
	i = 0;
	if (!queu)
		return (NULL);
	while (i < g->nbrp){
		queu[i] = i;
		i++;
	}
	return (queu);	
}

bool	ft_makecouverts(t_app *room){
	size_t	i;
	size_t	*queu;

	i = 0;
	queu = ft_make_queu(&room->g);
	while (i < room->g.nbrp){
		room->tds[i]->q = queu;
		pthread_create(&room->tds[i]->p->t_id, NULL, (void *)ft_routine, 
			(void *)((room->tds[i])));
		i++;
	}
	i = 0;
	while (i < room->g.nbrp)
		pthread_join(room->tds[i++]->p->t_id, NULL);
	
	return(true);
}

bool	ft_dinner(t_arg *g){
	t_app	room;

	if (ft_init(&room, g)){
		ft_makecouverts(&room);
		return (true);
	}
		// printf("%d\n", (int) g->nbrp);
	return (false);
}

int main(int n, char **v){
	t_arg	arg;

	if (n == 5 || n == 6)
	{
		if (ft_parse(n, v + 1, &arg)){
			if (ft_dinner(&arg))
				return (0);
			return (1);
		}
		return (ft_error("Au moins un de vos arguments est incorrecte..."));
	}
		return (ft_error("Il vous faut au moins 4 et au plus 5 arguments"));
}
