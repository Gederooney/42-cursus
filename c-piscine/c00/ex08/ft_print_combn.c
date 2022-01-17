/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rony Gédéon <ryebadok@student.42quebec.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:32:29 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/12 18:34:05 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	int		list[10];
	char	temp;
	int		i;
	int		position;
	int		k;

	k = 1;
	i = 0;
	temp = '0';
	while (k < 9)
	{
		list[k] = k;
		k++;
	}
}
