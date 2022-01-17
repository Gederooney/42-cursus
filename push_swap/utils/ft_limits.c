/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 08:46:41 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:39:18 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_get_max(int *a, size_t n)
{
	int	temp;

	temp = a[n - 1];
	while (n--)
		if (a[n] > temp)
			temp = a[n];
	return (temp);
}

int	ft_get_min(int *s, size_t n)
{
	int		temp;
	size_t	i;

	i = 0;
	temp = s[i];
	while (i < n)
	{
		if (s[i] < temp)
			temp = s[i];
		i++;
	}
	return (temp);
}

int	ft_ismin(int min, int *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s[i] < min)
			return (0);
		i++;
	}
	return (1);
}

int	ft_ismax(int max, int *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s[i] > max)
			return (0);
		i++;
	}
	return (1);
}

//get index of max
size_t	ft_indexofm(int *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		if (ft_ismax(s[i++], s, n))
			return (i - 1);
	return (n + 1);
}
