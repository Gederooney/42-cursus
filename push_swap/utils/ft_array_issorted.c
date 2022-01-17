/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_issorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:43:33 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/20 23:20:47 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_array_issorted(int *array, size_t n)
{
	while (n--)
		if (n != 0 && array[n] < array[n - 1])
			return (0);
	return (1);
}

int	ft_sort_intarray(int *array, size_t n)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (array[j] <= array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
			j++;
		}
		i++;
	}
	return (1);
}

// d stands for destination
int	ft_copyarray(int *src, int *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (1);
}
