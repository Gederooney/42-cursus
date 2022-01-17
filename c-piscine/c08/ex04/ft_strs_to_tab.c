/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:33:11 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/31 11:34:31 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

t_stock_str	*ft_create_memory(int ac, t_stock_str *rtn, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		(rtn + i)->copy = (char *)malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		i++;
	}
	return (rtn);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*rtn;
	int			i;

	i = 0;
	rtn = malloc(sizeof(t_stock_str) * (ac + 1));
	rtn = ft_create_memory(ac, rtn, av);
	while (i < ac)
	{
		(rtn + i)->size = ft_strlen(av[i]);
		(rtn + i)->str = av[i];
		ft_strcpy((rtn + i)->copy, av[i]);
		i++;
	}
	(rtn + i)->size = 0;
	(rtn + i)->str = 0;
	(rtn + i)->copy = 0;
	return (rtn);
}
