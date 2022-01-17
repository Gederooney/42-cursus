/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:05:08 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/25 18:32:29 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int nbr, char *base)
{
	char	*c;
	char	*temp;
	char	*rtn;

	rtn = malloc(sizeof(char *) * 2);
	*rtn = 0;
	if (nbr == 0)
	{
		*rtn = '0';
		*(rtn + 1) = 0;
	}
	while (nbr > 0)
	{
		c = malloc(sizeof(char *) * 2);
		*c = base[nbr % ft_strlen(base)];
		*(c + 1) = 0;
		temp = ft_strjoin(c, rtn);
		free (rtn);
		free (c);
		rtn = temp;
		nbr = nbr / ft_strlen(base);
	}
	return (rtn);
}

char	*ft_itoa_baseUI(unsigned int nbr, char *base)
{
	char	*c;
	char	*temp;
	char	*rtn;

	rtn = malloc(sizeof(char *) * 2);
	*rtn = 0;
	if (nbr == 0)
	{
		*rtn = '0';
		*(rtn + 1) = 0;
	}
	while (nbr > 0)
	{
		c = malloc(sizeof(char *) * 2);
		*c = base[nbr % ft_strlen(base)];
		*(c + 1) = 0;
		temp = ft_strjoin(c, rtn);
		free (rtn);
		free (c);
		rtn = temp;
		nbr = nbr / ft_strlen(base);
	}
	return (rtn);
}

char	*ft_itoa_baseUL(unsigned long nbr, char *base)
{
	char	*c;
	char	*temp;
	char	*rtn;

	rtn = malloc(sizeof(char *) * 2);
	*rtn = 0;
	if (nbr == 0)
	{
		*rtn = '0';
		*(rtn + 1) = 0;
	}
	while (nbr > 0)
	{
		c = malloc(sizeof(char *) * 2);
		*c = base[nbr % ft_strlen(base)];
		*(c + 1) = 0;
		temp = ft_strjoin(c, rtn);
		free (rtn);
		free (c);
		rtn = temp;
		nbr = nbr / ft_strlen(base);
	}
	return (rtn);
}
