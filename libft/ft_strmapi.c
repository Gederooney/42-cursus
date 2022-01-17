/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:41:39 by ryebadok          #+#    #+#             */
/*   Updated: 2021/05/17 11:24:09 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	int		i;

	rtn = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (*s)
	{
		rtn[i] = (*f)(i, *s);
		s++;
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
