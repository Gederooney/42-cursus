/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:52:13 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/16 19:22:06 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*rtn;
	unsigned int	i;

	rtn = dest;
	i = 0;
	while (i < size && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (*(src + i))
	{
		*(dest + i - 1) = '\0';
		while (*(src + i))
			i++;
	}
	else if (i < size)
		*(dest + i) = '\0';
	else if (i == size)
		*(dest + i - 1) = '\0';
	return (i);
}
