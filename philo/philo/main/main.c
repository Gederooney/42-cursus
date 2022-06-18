/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:13:46 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/18 06:31:44 by ryebadok         ###   ########.fr       */
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

bool	ft_makecouverts(t_app *table){
	size_t		i;
	// pthread_t	controller;

	i = 0;
	while (i < table->g.nbrp)
	{
		pthread_create(&table->tds[i]->p->t_id, NULL, (void *)ft_routine, 
			(void *)((table->tds[i])));
		i += 2;
		usleep(10);
	}
	i = 1;
	while (i < table->g.nbrp)
	{
		pthread_create(&table->tds[i]->p->t_id, NULL, (void *)ft_routine, 
			(void *)((table->tds[i])));
		i += 2;
		usleep(10);
	}
	// pthread_create(&controller, NULL, (void *)ft_controller, (void *)table);
	while (i < table->g.nbrp)
		pthread_join(table->tds[i++]->p->t_id, NULL);
	// pthread_join(controller, NULL);
	return(true);
}

bool	ft_dinner(t_arg *g){
	t_app	table;

	if (ft_init(&table, g)){
		ft_makecouverts(&table);
		return (true);
	}
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
