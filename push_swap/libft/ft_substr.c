/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 04:20:45 by ryebadok          #+#    #+#             */
/*   Updated: 2021/05/17 11:21:52 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*rtn;
	size_t	count;

	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	rtn = sub;
	count = 0;
	while (count < len && (int)start < ft_strlen(s))
	{
		*sub = s[start];
		sub++;
		start++;
		count++;
	}
	*sub = 0;
	return (rtn);
}
