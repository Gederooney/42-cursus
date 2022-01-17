/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:11:32 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/08 13:50:19 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_res;

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

void	ft_res(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Signal reçu, ", STDOUT_FILENO);
		ft_putstr_fd("le processus va maintenant être fermé", STDOUT_FILENO);
		g_res = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	int					i;

	action.sa_flags = 0;
	action.sa_handler = ft_res;
	action.sa_mask = 0;
	g_res = 1;
	if (argc != 3)
		ft_usage();
	else
	{
		sigaction(SIGUSR1, &action, NULL);
		while (argv[2][i])
			ft_send_bybit(ft_atoi(argv[1]), argv[2][i++]);
		ft_send_bybit(ft_atoi(argv[1]), 0);
		while (g_res)
			;
	}
	return (0);
}
