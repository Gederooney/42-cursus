/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:22:18 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/26 10:28:21 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	char	*rtn;

	str = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	rtn = str;
	while (*src)
	{
		*str = *src;
		str++;
		src++;
	}
	*str = '\0';
	return (rtn);
}
