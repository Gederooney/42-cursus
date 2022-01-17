/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:25:18 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:33:32 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(int *a, size_t *x)
{
	int	temp;

	temp = a[*x - 1];
	ft_shift_right(a, *x - 1);
	a[0] = temp;
	write(1, "rra\n", 4);
}

void	ft_rrb(int *b, size_t *y)
{
	int	temp;

	temp = b[*y - 1];
	ft_shift_right(b, *y - 1);
	b[0] = temp;
	write(1, "rrb\n", 4);
}

void	ft_rrr(int *a, int *b, size_t *x, size_t *y)
{
	int	temp;

	temp = a[*x - 1];
	ft_shift_right(a, *x - 1);
	a[0] = temp;
	temp = b[*y - 1];
	ft_shift_right(b, *y - 1);
	b[0] = temp;
	write(1, "rrr\n", 4);
}
