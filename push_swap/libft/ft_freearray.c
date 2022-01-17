/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:48:09 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/18 02:32:04 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearray(char **array)
{
	int		i;
	char	**start;

	i = 0;
	start = array;
	if (!array)
		return ;
	while (*array)
	{
		ft_myfree(*array);
		array++;
	}
	ft_myfree(*array);
	free (start);
}
