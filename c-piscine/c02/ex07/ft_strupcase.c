/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:44:22 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/16 11:43:40 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*rtn;

	rtn = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
	return (rtn);
}
