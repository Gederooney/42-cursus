/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:09:12 by ryebadok          #+#    #+#             */
/*   Updated: 2022/05/31 23:46:20 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_shift_left(int *tab, int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		tab[i - 1] = tab[i];
		i++;
	}
}

void	ft_ra(int *a, int x)
{
	int	temp;

	temp = a[0];
	ft_shift_left(a, x - 1);
	a[x - 1] = temp;
}
