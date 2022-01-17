/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:45:54 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/23 12:28:55 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	srclen;
	unsigned int	destlen;
	unsigned int	i;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = 0;
	if (destlen > size || destlen == size)
		return (size + srclen);
	else if (destlen < size)
	{
		while (destlen + i < size - 1 && *src)
		{
			*(dest + destlen + i) = *src;
			src++;
			i++;
		}
		*(dest + destlen + i) = '\0';
	}
	return (destlen + srclen);
}
