/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 08:43:48 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/10 08:45:34 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putintarray(int *array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putnbr(array[i]);
		ft_putchar('\n');
		i++;
	}
}
