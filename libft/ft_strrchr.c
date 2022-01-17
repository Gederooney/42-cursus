/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:17:14 by ryebadok          #+#    #+#             */
/*   Updated: 2021/05/05 10:24:21 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*rtn;

	rtn = NULL;
	while (*str)
	{
		if (*str == (char)c)
			rtn = (char *)str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (rtn);
}
