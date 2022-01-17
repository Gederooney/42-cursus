/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:49:48 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/08 13:50:07 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_usage(void)
{
	ft_putstr_fd("--Help manual--\n\n", STDOUT_FILENO);
	ft_putstr_fd("SYNOPSIS\n	./client s_pid message\n", STDOUT_FILENO);
	ft_putstr_fd("--Help manual--\n", STDOUT_FILENO);
}

void	ft_send_bybit(int pid, char msg)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((msg >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		ft_usage();
	else
	{
		while (argv[2][i])
			ft_send_bybit(ft_atoi(argv[1]), argv[2][i++]);
		ft_send_bybit(ft_atoi(argv[1]), 0);
	}
	return (0);
}
