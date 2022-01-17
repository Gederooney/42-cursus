/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:05:08 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/18 02:16:03 by ryebadok         ###   ########.fr       */
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

char	*ft_itoa_baseui(unsigned int nbr, char *base)
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

char	*ft_itoa_baseul(unsigned long nbr, char *base)
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
