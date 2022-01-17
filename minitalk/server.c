/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:49:48 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/08 13:21:57 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_usage(void)
{
}

void	ft_interpret(int sig)
{
	static char	c = 0;
	static int	bit = 0;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8 && !c)
	{	
		ft_putstr_fd("\n\n", STDOUT_FILENO);
		c = 0;
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
	if (argc != 1)
		ft_usage();
	else
	{
		ft_putstr_fd("The Server pid is: ", STDOUT_FILENO);
		ft_putnbr_fd(getpid(), STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		signal(SIGUSR1, ft_interpret);
		signal(SIGUSR2, ft_interpret);
		while (1)
			;
	}
}
