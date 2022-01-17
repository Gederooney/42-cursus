/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:58:05 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/17 13:55:21 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char				*rtn;
	unsigned int		i;

	rtn = dest;
	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (i < n)
	{
		while (i < n)
		{
			*(dest + i) = '\0';
			i++;
		}
	}
	return (rtn);
}
