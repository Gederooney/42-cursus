/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:12:22 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/25 15:00:03 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iputstr(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		ft_putchar(*s);
		s++;
		i++;
	}
	return (i);
}
