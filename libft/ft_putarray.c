/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 08:40:09 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/10 08:42:05 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putstr(array[i]);
		ft_putstr("\n");
		i++;
	}
}
