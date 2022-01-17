/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_intarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 02:33:17 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:38:45 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	ft_free_intarray(int *s, size_t count)
{
	while (count--)
		ft_myfree(&(s[count]));
}

int	ft_med(int *a, size_t c)
{
	int		som;
	size_t	i;

	i = 0;
	som = 0;
	while (i < c)
		som += a[i++];
	return (som / (int)c);
}
