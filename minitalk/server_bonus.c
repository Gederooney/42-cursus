/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:49:48 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/07 14:49:11 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_usage(void)
{
}

void	ft_interpret(int sig, siginfo_t *infos, void *context)
{
	static char	c = 0;
	static int	bit = 0;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8 && !c)
	{	
		ft_putchar_fd('\n', STDOUT_FILENO);
		kill(infos->si_pid, SIGUSR1);
		bit = 0;
	}
	else if (bit == 8)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_interpret;
	action.sa_mask = 0;
	if (argc != 1)
		ft_usage();
	else
	{
		ft_putstr_fd("The Server pid is: ", STDOUT_FILENO);
		ft_putnbr_fd(getpid(), STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		while (1)
			;
	}
}
