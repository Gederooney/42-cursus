/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:23:37 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/26 13:23:43 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	*rtn;

	if (max <= min)
		return (NULL);
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	rtn = tab;
	while (min < max)
	{
		*tab = min;
		min++;
		tab++;
	}
	return (rtn);
}
