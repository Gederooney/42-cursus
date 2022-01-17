/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:07:52 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/08 13:50:16 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_isFlag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

void	ft_printwidth(int n)
{
	while (n-- > 0)
		write (1, " ", 1);
}

int	ft_specifier(char c)
{
	if (c == 'd')
		return (1);
	else if (c == 'c')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	return (0);
}


int	ft_getnbrcount(int nbr)
{
	int	count;

	count = 0;
	while (nbr > 0)
	{
		count++;
		nbr = nbr / 10;
	}
	if (nbr < 0)
		return (count + 1);
	return (count);
}

int	ft_writeloop(int n, char c)
{
	int	i;
	
	i = 0;
	while (i++ < n)
		write (1, &c, 1);
	return (i - 1);
}
