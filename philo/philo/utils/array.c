/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:18:45 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 11:07:58 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	*ft_create_queu(int n)
{
	int	*rtn;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (!(n % 2))
		k = (n / 2) + 1;
	else
		k = n / 2;
	rtn = malloc(sizeof(int) * n);
	if (!rtn)
		return (NULL);
	while (i < n)
	{
		if (!(i % 2))
			rtn[j++] = i++;
		else
			rtn[k++] = i++;
	}
	return (rtn);
}
