/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:09:12 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/17 11:25:11 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_print_arr(size_t count, size_t *array)
{
	size_t	i;

	i = 0;
	while (i < count)
		printf("%d\n", (int)array[i++]);
}

void	ft_shift_left(size_t *tab, size_t n)
{
	size_t	i;

	i = 1;
	while (i <= n)
	{
		tab[i - 1] = tab[i];
		i++;
	}
}

void	ft_ra(size_t *a, size_t x)
{
	size_t	temp;

	temp = a[0];
	ft_shift_left(a, x - 1);
	a[x - 1] = temp;
}
