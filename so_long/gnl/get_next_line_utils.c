/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:20:54 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/09 11:24:53 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	char	*rtn;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	rtn = join;
	if (!join)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = 0;
	return (rtn);
}

char	*ft_strchr(const char *str, int c)
{
	char	*rtn;

	rtn = NULL;
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (rtn);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_substr(char *s, int start, size_t len)
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

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*rtn;

	dup = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!dup)
		return (NULL);
	rtn = dup;
	while (*s)
		*dup++ = *s++;
	*dup = 0;
	return (rtn);
}
