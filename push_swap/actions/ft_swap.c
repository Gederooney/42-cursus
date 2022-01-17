/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 08:24:04 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:33:48 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(int *a, size_t *x)
{
	int	temp;

	if (*x <= 1)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write(1, "sa\n", 3);
}

void	ft_sb(int *b, size_t *y)
{
	int	temp;

	if (*y <= 1)
		return ;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write(1, "sb\n", 3);
}

void	ft_ss(int *a, int *b, size_t *x, size_t *y)
{
	int	temp;

	if (*x <= 1 || *y <= 1)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write(1, "ss\n", 3);
}
