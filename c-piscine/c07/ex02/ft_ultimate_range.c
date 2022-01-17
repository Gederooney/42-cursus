/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:18:21 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/30 10:21:51 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	debut;

	debut = min;
	i = 0;
	*range = (int *)malloc(sizeof(**range) * (max - min));
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	if (*range == NULL)
	{
		*range = 0;
		return (-1);
	}
	while (i < (max - min))
	{
		(*range)[i] = debut;
		debut++;
		i++;
	}
	return ((max - min));
}
