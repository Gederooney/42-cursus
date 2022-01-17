/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 08:31:44 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:32:46 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_shift_left(int *tab, size_t n)
{
	size_t	i;

	i = 1;
	while (i <= n)
	{
		tab[i - 1] = tab[i];
		i++;
	}
}

void	ft_shift_right(int	*tab, size_t n)
{
	while (n > 0)
	{
		tab[n] = tab[n - 1];
		n--;
	}
}

void	ft_pa(int *a, int *b, size_t *x, size_t *y)
{
	if (!*y)
		return ;
	ft_shift_right(a, *x);
	a[0] = b[0];
	ft_shift_left(b, *y);
	b[*y] = 0;
	*x += 1;
	*y -= 1;
	write(1, "pa\n", 3);
}

void	ft_pb(int *b, int *a, size_t *y, size_t *x)
{
	if (!*x)
		return ;
	ft_shift_right(b, *y);
	b[0] = a[0];
	*y += 1;
	*x -= 1;
	ft_shift_left(a, *x);
	a[*x] = 0;
	write(1, "pb\n", 3);
}
