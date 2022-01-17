/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:02:09 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 10:48:13 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int n, char **p)
{
	t_var		*var;
	t_g			**g;

	if (n == 5 || n == 6)
	{
		var = ft_parse(p + 1, n - 1);
		if (!var)
			return (ft_errors(200));
		g = ft_initthreads(var);
		pthread_exit(NULL);
		return (0);
	}
	return (ft_errors(100));
}
