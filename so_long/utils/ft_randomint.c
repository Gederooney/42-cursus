/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randomint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:45:08 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/27 06:54:04 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include <stdio.h>

int	ft_rand(int x, int y)
{
	unsigned long	z;
	int				*w;

	w = malloc(sizeof(int));
	z = (unsigned long)(&w);
	if (y <= x)
		return (-1);
	return ((z % (y - x + 1)) + x);
}

int	main(void)
{
	int	i;

	i = 9;
	while (i--)
		printf("%d\n", ft_rand(0, 4));
	return (0);
}
