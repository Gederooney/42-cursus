/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:13:46 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/01 19:51:55 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
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

bool	ft_serve(t_app app){
	printf("%d\n", (int)app.t[app.g->nbrp - 1].id);
	return (true);
}

bool	ft_dinner(t_arg *g){
	t_app	app;

	if (ft_init(&app, g)){
		ft_serve(app);
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
