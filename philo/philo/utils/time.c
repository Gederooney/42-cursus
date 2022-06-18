/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:31:55 by ryebadok          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/06/18 06:24:47 by ryebadok         ###   ########.fr       */
=======
/*   Updated: 2022/06/18 08:36:56 by ryebadok         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(size_t t)
{
	size_t	s_time;
	
	s_time = ft_get_time();
<<<<<<< Updated upstream
	printf("%ld\n", t);
=======
>>>>>>> Stashed changes
	while (ft_get_time() - s_time < t)
		usleep(t / 10);
}
