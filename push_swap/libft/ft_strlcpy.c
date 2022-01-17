/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:14:49 by ryebadok          #+#    #+#             */
/*   Updated: 2021/05/13 00:27:39 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		if (dstsize <= (size_t)ft_strlen(src) && dstsize > 0)
			dst[i - 1] = '\0';
		else
			dst[i] = '\0';
	}
	return ((size_t)ft_strlen(src));
}
