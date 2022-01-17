/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:01:19 by ryebadok          #+#    #+#             */
/*   Updated: 2021/05/11 15:23:04 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dest;
	char	*source;
	size_t	remaining;
	size_t	dest_len;

	dest = dst;
	source = (char *)src;
	remaining = dstsize;
	while (remaining-- != 0 && *dest != '\0')
		dest++;
	dest_len = dest - dst;
	remaining = dstsize - dest_len;
	if (remaining == 0)
		return (dest_len + ft_strlen(src));
	while (*source)
	{
		if (remaining > 1)
		{
			*dest++ = *source;
			remaining--;
		}
		source++;
	}
	*dest = '\0';
	return (dest_len + (source - src));
}
