/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:28:55 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/30 10:33:57 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_nbrc(int size, char **strs)
{
	int	i;
	int	nbrc;

	i = 0;
	nbrc = 0;
	while (i < size)
	{
		nbrc += ft_strlen(strs[i]);
		i++;
	}
	return (nbrc);
}

char	*ft_put_str(char *addr, char *str)
{
	while (*str)
	{
		*addr = *str;
		addr++;
		str++;
	}
	return (addr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joint;
	int		nbrc;
	int		s;
	char	*rtn;
	int		i;

	s = ft_strlen(sep);
	if (size == 0)
	{
		joint = (char *)malloc(sizeof(char) * 1);
		*joint = '\0';
		return (joint);
	}
	nbrc = ft_nbrc(size, &*strs);
	joint = (char *)malloc((sizeof(char) * nbrc * (size - 1) * s) + 1);
	rtn = joint;
	i = 0;
	while (i < size)
	{
		joint = ft_put_str(joint, strs[i]);
		if (i != size - 1)
			joint = ft_put_str(joint, sep);
		i++;
	}
	return (rtn);
}
