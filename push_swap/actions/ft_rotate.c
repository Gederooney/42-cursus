/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:45:50 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:33:02 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(int *a, size_t *x)
{
	int	temp;

	temp = a[0];
	ft_shift_left(a, *x - 1);
	a[*x - 1] = temp;
	write(1, "ra\n", 3);
}

void	ft_rb(int *b, size_t *y)
{
	int	temp;

	temp = b[0];
	ft_shift_left(b, *y - 1);
	b[*y - 1] = temp;
	write(1, "rb\n", 3);
}

void	ft_rr(int *a, int *b, size_t *x, size_t *y)
{
	int	temp;

	temp = a[0];
	ft_shift_left(a, *x - 1);
	a[*x - 1] = temp;
	temp = b[0];
	ft_shift_left(b, *y - 1);
	b[*y - 1] = temp;
	write(1, "rb\n", 3);
}
